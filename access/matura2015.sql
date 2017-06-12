a)

SELECT ( SELECT "Rok" FROM "wyscigi" WHERE "Id_wyscigu" = "wyniki"."Id_wyscigu" ), ( SELECT "GrandPrix" FROM "wyscigi" WHERE "Id_wyscigu" = "wyniki"."Id_wyscigu" ), "Id_wyscigu", SUM( "Punkty" ) FROM "wyniki" WHERE "Id_kierowcy" = 'z45' GROUP BY "Id_wyscigu" ORDER BY SUM( "Punkty" ) DESC LIMIT 1

b)

SELECT "GrandPrix", COUNT( * ) FROM "wyscigi" GROUP BY "GrandPrix" ORDER BY COUNT( * ) ASC

c)

SELECT ( SELECT "Imie" FROM "kierowcy" WHERE "Id_kierowcy" = "wyniki"."Id_kierowcy" ), ( SELECT "Nazwisko" FROM "kierowcy" WHERE "Id_kierowcy" = "wyniki"."Id_kierowcy" ), "Id_kierowcy", SUM( "Punkty" ) FROM "wyniki" WHERE ( SELECT "Rok" FROM "wyscigi" WHERE "Id_wyscigu" = "wyniki"."Id_wyscigu" ) = 2000 GROUP BY "Id_kierowcy" ORDER BY SUM( "Punkty" ) DESC LIMIT 1

d)

SELECT SUM( 1 ), SUM( "Punkty" ), "b"."Kraj", COUNT( DISTINCT "Id_kierowcy" ) FROM "wyniki" AS "a" RIGHT JOIN "kierowcy" AS "b" ON "a"."Id_kierowcy" = "b"."Id_kierowcy" WHERE ( SELECT "Rok" FROM "wyscigi" WHERE "Id_wyscigu" = "a"."Id_wyscigu" ) = 2012 GROUP BY "b"."Kraj"
