classifica :: Float -> Float -> String
classifica peso altura | imc < 18.5 = "baixo peso"
                       | imc < 25 = "peso normal"
                       | imc < 30 = "excesso de peso"
                       | otherwise = "obesidade"
           where imc = peso / (altura^2)
