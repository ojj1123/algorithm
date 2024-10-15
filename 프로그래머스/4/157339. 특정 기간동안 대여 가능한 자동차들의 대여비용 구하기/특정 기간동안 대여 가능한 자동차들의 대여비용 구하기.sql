# SELECT c.CAR_ID, c.CAR_TYPE, FLOOR((30*c.DAILY_FEE)*(1-p.DISCOUNT_RATE/100)) as FEE, h.START_DATE, h.END_DATE
# FROM CAR_RENTAL_COMPANY_CAR c
# INNER JOIN
# (SELECT * FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN WHERE DURATION_TYPE='30일 이상') p
# ON c.CAR_TYPE=p.CAR_TYPE
# LEFT JOIN (SELECT CAR_ID, START_DATE, END_DATE FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY WHERE START_DATE > '2022-11-30' OR END_DATE < '2022-11-01' GROUP BY CAR_ID) h
# ON c.CAR_ID=h.CAR_ID
# WHERE c.CAR_TYPE IN ('세단', 'SUV') AND
# (30*c.DAILY_FEE)*(1-p.DISCOUNT_RATE/100) >= 500000 AND
# (30*c.DAILY_FEE)*(1-p.DISCOUNT_RATE/100) < 2000000
# ORDER BY FEE DESC, CAR_TYPE, CAR_ID DESC;

SELECT a.car_id,
       a.car_type,
       round((daily_fee * 30 * (100 - CAST(replace(discount_rate, '%', '') AS unsigned))) / 100,
             0) AS fee
FROM car_rental_company_car a
         JOIN (SELECT car_id,
                      COUNT(
                              CASE
                                  WHEN start_date > '2022-11-30' OR end_date < '2022-11-01'
                                      THEN NULL
                                  ELSE 1
                                  END) AS temp
               FROM car_rental_company_rental_history
               GROUP BY car_id
               HAVING temp = 0) b ON a.car_id = b.car_id
         JOIN (SELECT *
               FROM car_rental_company_discount_plan
               WHERE duration_type LIKE '30%') c ON a.car_type = c.car_type
having 500000 <= FEE AND  FEE <= 2000000
ORDER BY 3 DESC, 2, 1 DESC