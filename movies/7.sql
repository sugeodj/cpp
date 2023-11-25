select m.title, r.rating from movies m
join ratings r on r.movie_id = m.id
where m.year = 2010
order by r.rating desc, m.title