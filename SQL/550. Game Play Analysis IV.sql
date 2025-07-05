SELECT
    ROUND(
        COUNT(*) / (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM (
    SELECT DISTINCT a1.player_id
    FROM Activity a1
    JOIN Activity a2
      ON a1.player_id = a2.player_id
     AND DATEDIFF(a2.event_date, a1.event_date) = 1
    WHERE a1.event_date = (
        SELECT MIN(a3.event_date)
        FROM Activity a3
        WHERE a3.player_id = a1.player_id
    )
) AS first_day_follow_up;

-- #link:https://leetcode.com/problems/game-play-analysis-iv/
-- #id:550