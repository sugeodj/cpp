SELECT AVG(energy) AS avgEnergy
FROM songs AS s
JOIN artists AS a ON a.id = s.artist_id
WHERE a.name LIKE "Drake"
LIMIT 1