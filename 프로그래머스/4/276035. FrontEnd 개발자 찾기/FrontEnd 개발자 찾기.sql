select id, email, first_name, last_name
from developers
where (select count(*) from skillcodes where skillcodes.code & developers.skill_code = skillcodes.code and category = 'Front End') > 0
order by id
