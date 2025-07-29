-- Top user
SELECT * FROM (
    SELECT name AS results
    FROM (
        SELECT u.name, COUNT(m.movie_id) AS countt
        FROM Users AS u
        LEFT JOIN MovieRating AS m ON u.user_id = m.user_id
        GROUP BY u.user_id
    ) AS final_data
    WHERE countt = (
        SELECT MAX(countt)
        FROM (
            SELECT u.name, COUNT(m.movie_id) AS countt
            FROM Users AS u
            LEFT JOIN MovieRating AS m ON u.user_id = m.user_id
            GROUP BY u.user_id
        ) AS sub_data
    )
    order by name LIMIT 1
) AS top_user

UNION ALL

-- Top movie
SELECT * FROM (
    SELECT avg_data.title AS results
    FROM (
        SELECT mov.title, AVG(mr.rating) AS avgg
        FROM Movies AS mov
        LEFT JOIN MovieRating AS mr ON mov.movie_id = mr.movie_id
        WHERE mr.created_at >= '2020-02-01' AND mr.created_at <= '2020-02-29'
        GROUP BY mov.title
    ) AS avg_data
    WHERE avgg = (
        SELECT MAX(sub.avgg)
        FROM (
            SELECT mov2.title, AVG(mr2.rating) AS avgg
            FROM Movies AS mov2
            LEFT JOIN MovieRating AS mr2 ON mov2.movie_id = mr2.movie_id
            WHERE mr2.created_at >= '2020-02-01' AND mr2.created_at <= '2020-02-29'
            GROUP BY mov2.title
        ) AS sub
    )
    order by avg_data.title LIMIT 1
) AS top_movie;

-- sol 2 

WITH user_counts AS (
    SELECT u.name AS results, COUNT(m.movie_id) AS countt
    FROM Users AS u
    LEFT JOIN MovieRating AS m ON u.user_id = m.user_id
    GROUP BY u.user_id
),
top_movies AS (
    SELECT mov.title AS results, AVG(mr.rating) AS avgg
    FROM Movies AS mov
    LEFT JOIN MovieRating AS mr ON mov.movie_id = mr.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY mov.title
)

-- Final result: Top user + Top movie
SELECT results FROM user_counts
WHERE countt = (SELECT MAX(countt) FROM user_counts)
ORDER BY results
LIMIT 1

UNION ALL

SELECT results FROM top_movies
WHERE avgg = (SELECT MAX(avgg) FROM top_movies)
ORDER BY results
LIMIT 1;
