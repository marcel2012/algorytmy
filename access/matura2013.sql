a)

SELECT * FROM "hobby" WHERE SUBSTR( "nazwa", 0, 1 ) = 'k'

b)

SELECT COUNT( * ) FROM "ma_hobby" WHERE "hobby" = ( SELECT "hobby"."hobby" FROM "hobby" WHERE "hobby"."nazwa" = 'majsterkowanie' )

c)

SELECT * FROM "ma_hobby" INNER JOIN "osoby" ON "ma_hobby"."idos" = "osoby"."idos" WHERE "hobby" = ( SELECT "hobby"."hobby" FROM "hobby" WHERE "hobby"."nazwa" = 'programowanie' ) ORDER BY "nazwisko" ASC

d)

SELECT * FROM "osoby" AS "a" INNER JOIN ( SELECT "idos", SUM( 1 ) AS "n" FROM "ma_hobby" GROUP BY "idos" ) AS "b" ON "a"."idos" = "b"."idos" WHERE "n" > 4 ORDER BY "nazwisko", "imie"

e)

SELECT ( SELECT "nazwa" FROM "hobby" WHERE "hobby" = "a"."hobby" ), "hobby", SUM( 1 ) AS "n" FROM "ma_hobby" AS "a" GROUP BY "a"."hobby" ORDER BY "n" DESC
