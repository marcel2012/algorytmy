a)

SELECT "Wiek", SUM( 1 ) FROM "dzieci" GROUP BY "Wiek"

b)

SELECT SUM( 1 ), "Plec", "Id_przedszkola" FROM "dzieci" WHERE "Id_przedszkola" = ( SELECT "Id_przedszkola" FROM "przedszkola" WHERE "Nazwa_przedszkola" = 'Przedszkole nr 28 Srebrna Kotwica' ) OR "Id_przedszkola" = ( SELECT "Id_przedszkola" FROM "przedszkola" WHERE "Nazwa_przedszkola" = 'Przedszkole nr 49 im. Panienki z Okienka' ) OR "Id_przedszkola" = ( SELECT "Id_przedszkola" FROM "przedszkola" WHERE "Nazwa_przedszkola" = 'Przedszkole nr 87 Gwiezdna Kraina' ) GROUP BY "Plec", "Id_przedszkola"

c)

SELECT "Id_przedszkola", COUNT( * ) FROM "dzieci" WHERE "Wiek" = 3 GROUP BY "Id_przedszkola" ORDER BY COUNT( * ) DESC

d)

SELECT "Id_przedszkola", COUNT( * ) - ( SELECT "Liczba_miejsc" FROM "przedszkola" WHERE "Id_przedszkola" = "dzieci"."Id_przedszkola" ) FROM "dzieci" GROUP BY "Id_przedszkola" ORDER BY COUNT( * ) DESC
