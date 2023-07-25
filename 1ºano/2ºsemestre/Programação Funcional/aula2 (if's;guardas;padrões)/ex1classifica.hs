classifica1 :: Int -> String
classifica1 n = if n <= 9
                 then "reprovado"
                 else if n > 9 && n <= 12
                  then "suficiente"
                  else if n > 12 && n <= 15
                   then "bom"
                   else if n > 15 && n <= 18
                    then "muito bom"
                    else if n > 18 && n <= 20
                     then "muito bom com distincao"
                     else error "valor inválido"


classifica2 :: Int -> String
classifica2 n | n <= 9            = "reprovado"
              | n > 9 && n <= 12  = "suficiente"
              | n > 12 && n <= 15 = "bom"
              | n > 15 && n <= 18 = "muito bom"
              | n > 18 && n <= 20 = "muito bom com distincao"
