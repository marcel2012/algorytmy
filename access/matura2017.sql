4.1

SELECT SUM( "masa" ), "nip" FROM "cukier" GROUP BY "nip" ORDER BY SUM( "masa" ) DESC LIMIT 3

4.2

SELECT SUM( "masa" * ( SELECT "cena" FROM "cennik" WHERE "data" = SUBSTR( "cukier"."data", 0, 4 ) ) ) FROM "cukier"

4.3

SELECT SUM( "masa" ), SUBSTR( "data", 0, 4 ) FROM "cukier" GROUP BY SUBSTR( "data", 0, 4 )

4.4 

SELECT SUM( CASE WHEN ( SELECT SUM( "masa" ) FROM "cukier" AS "b" WHERE "b"."data" <= "a"."data" AND "a"."nip" = "b"."nip" ) >= 100 AND ( SELECT SUM( "masa" ) FROM "cukier" AS "b" WHERE "b"."data" <= "a"."data" AND "a"."nip" = "b"."nip" ) < 1000 THEN 5 WHEN ( SELECT SUM( "masa" ) FROM "cukier" AS "b" WHERE "b"."data" <= "a"."data" AND "a"."nip" = "b"."nip" ) >= 1000 AND ( SELECT SUM( "masa" ) FROM "cukier" AS "b" WHERE "b"."data" <= "a"."data" AND "a"."nip" = "b"."nip" ) < 10000 THEN 10 WHEN ( SELECT SUM( "masa" ) FROM "cukier" AS "b" WHERE "b"."data" <= "a"."data" AND "a"."nip" = "b"."nip" ) >= 10000 THEN 20 END ) FROM "cukier" AS "a"

4.5

SELECT COUNT( * ) FROM ( SELECT SUBSTR( "a"."data", 0, 7 ) FROM "cukier" AS "a" WHERE ( SELECT - 5 + CEILING( SUM( "masa" ) / 1000 ) FROM "cukier" AS "b" WHERE SUBSTR( "b"."data", 0, 7 ) <= SUBSTR( "a"."data", 0, 7 ) ) - ( SELECT - 5 + CEILING( SUM( "masa" ) / 1000 ) FROM "cukier" AS "b" WHERE SUBSTR( "b"."data", 0, 7 ) < SUBSTR( "a"."data", 0, 7 ) ) >= 4 GROUP BY SUBSTR( "a"."data", 0, 7 ) )

5.1

a)

SELECT "a"."Rodzaj_meczu", COUNT( * ) FROM "wyniki" AS "a" LEFT JOIN "druzyny" AS "b" ON "a"."Id_druzyny" = "b"."Id_druzyny" WHERE "b"."Miasto" = 'Kucykowo' GROUP BY "a"."Rodzaj_meczu"

b)

SELECT SUBSTR( "Data_meczu", 0, 4 ), COUNT( * ) FROM "wyniki" AS "a" LEFT JOIN "druzyny" AS "b" ON "a"."Id_druzyny" = "b"."Id_druzyny" WHERE "b"."Miasto" = 'Kucykowo' GROUP BY SUBSTR( "Data_meczu", 0, 4 ) ORDER BY COUNT( * ) DESC LIMIT 1

5.2

SELECT * FROM ( SELECT SUM( "Bramki_stracone" ) AS "b", SUM( "Bramki_zdobyte" ) AS "c", "Id_druzyny", ( SELECT "Nazwa" FROM "druzyny" WHERE "Id_druzyny" = "wyniki"."Id_druzyny" ) FROM "wyniki" GROUP BY "Id_druzyny" ) AS "a" WHERE "a"."b" = "a"."c"

5.3

SELECT COUNT( * ) FROM "wyniki" WHERE ( "Bramki_zdobyte" - "Bramki_stracone" ) > 0;
SELECT COUNT( * ) FROM "wyniki" WHERE ( "Bramki_zdobyte" - "Bramki_stracone" ) < 0;
SELECT COUNT( * ) FROM "wyniki" WHERE ( "Bramki_zdobyte" - "Bramki_stracone" ) = 0

5.4

SELECT COUNT( * ) FROM "sedziowie" WHERE ( SELECT COUNT( * ) FROM "wyniki" WHERE "Nr_licencji" = "sedziowie"."Nr_licencji" AND "Rodzaj_meczu" = 'P' ) = 0

6.1

    for(int y=0; y<m; y++)
        for(int x=0; x<n; x++)
            if(dane[y][x]<mini)
                mini=dane[y][x];
            else if(dane[y][x]>maxi)
                maxi=dane[y][x];

6.2

    for(int y=0; y<m; y++)
        for(int x=0; x<n; x++)
            if(dane[y][x]!=dane[y][n-1-x])
            {
                wynik++;
                break;
            }

6.3

    for(int y=0; y<m; y++)
        for(int x=0; x<n; x++)
        {
            bool zlicz=true;
            if(y)
                if(dane[y][x]-dane[y-1][x]>128 || dane[y][x]-dane[y-1][x]<-128)
                {
                    wynik+=zlicz;
                    zlicz=false;
                }
            if(y+1<m)
                if(dane[y][x]-dane[y+1][x]>128 || dane[y][x]-dane[y+1][x]<-128)
                {
                    wynik+=zlicz;
                    zlicz=false;
                }
            if(x)
                if(dane[y][x]-dane[y][x-1]>128 || dane[y][x]-dane[y][x-1]<-128)
                {
                    wynik+=zlicz;
                    zlicz=false;
                }
            if(x+1<n)
                if(dane[y][x]-dane[y][x+1]>128 || dane[y][x]-dane[y][x+1]<-128)
                {
                    wynik+=zlicz;
                    zlicz=false;
                }
        }

6.4

    for(int x=0; x<n; x++)
    {
        int start=0;
        while(start<m)
        {
            int kolor=dane[start][x];
            int tmp=0;
            while(start<m && dane[start][x]==kolor)
            {
                start++;
                tmp++;
            }
            if(tmp>maks)
                maks=tmp;
        }
    }
