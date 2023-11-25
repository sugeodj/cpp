select count(m.title) from movies m
join ratings r on r.movie_id = m.id
where r.rating = 10.0
limit 1