a)

SELECT "imie", "nazwisko" FROM "kandydaci" WHERE "matematyka" + "informatyka" + "fizyka" + "jezykobcy" >= 400 ORDER BY "nazwisko"

b)

SELECT "kierunek", COUNT( * ) FROM "zgloszenia" WHERE "kierunek" = 'matematyka' OR "kierunek" = 'informatyka' OR "kierunek" = 'fizyka' GROUP BY "kierunek"

c)

SELECT "imie", "nazwisko" FROM "kandydaci" WHERE ( SELECT COUNT( * ) FROM "zgloszenia" WHERE "idosoby" = "kandydaci"."idosoby" ) = 5

d)

SELECT COUNT( * ) FROM "kandydaci" WHERE ( SELECT COUNT( * ) FROM "zgloszenia" WHERE "idosoby" = "kandydaci"."idosoby" ) > 0 AND "plec" = 'm'

SELECT COUNT( * ) FROM "kandydaci" WHERE ( SELECT COUNT( * ) FROM "zgloszenia" WHERE "idosoby" = "kandydaci"."idosoby" ) > 0 AND "plec" = 'k'

e)

SELECT AVG( "matematyka" ) FROM "kandydaci" WHERE ( SELECT COUNT( * ) FROM "zgloszenia" WHERE "idosoby" = "kandydaci"."idosoby" AND "kierunek" = 'fizyka' ) > 0
