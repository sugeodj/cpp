select distinct p.name
FROM people p
join stars s on p.id = s.person_id
join movies m on s.movie_id = m.id
join stars s2 on m.id = s2.movie_id
join people p2 on s2.person_id = p2.id
where p2.name = 'Kevin Bacon' and p2.birth = 1958 and p.name != 'Kevin Bacon';
