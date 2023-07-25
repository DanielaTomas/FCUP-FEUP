{-
   A cifra de César em Haskell
   Pedro Vasconcelos, 2010
   baseado na solução em  "Programming in Haskell",  Graham Hutton, 2007
-}
import Data.Char (chr, ord)

-- Converte letras em inteiros 0..25 e vice-versa
letraInt :: Char -> Int
letraInt c = ord c - ord 'A'

intLetra :: Int -> Char
intLetra n = chr (n + ord 'A')

maiúscula :: Char -> Bool
maiúscula x = x>='A' && x<='Z'

-- Efectuar um deslocamento de k posições
desloca :: Int -> Char -> Char
desloca k x | maiúscula x = intLetra ((letraInt x + k)`mod`26)
            | otherwise   = x

-- Repetir o deslocamento para toda a cadeia de caracteres.
cifrar :: Int -> String -> String
cifrar k xs = [desloca k x | x<-xs]



{-
---------------------------------------------------------
 Quebrar a cifra de César usando contagem de frequências
---------------------------------------------------------
-}

-- Frequências das letras A .. Z em português
tabelaPT :: [Float]
tabelaPT = [13.9, 1.0, 4.4, 5.4, 12.2, 1.0,
            1.2, 0.8, 6.9, 0.4, 0.1, 2.8, 4.2,
            5.3, 10.8, 2.9, 0.9, 6.9, 7.9, 4.9,
            4.0, 1.3, 0.01, 0.3, 0.01, 0.4]


-- Contar ocorrências de um caracter numa cadeia
ocorrências :: Char -> String -> Int
ocorrências y xs = length [x | x<-xs, x==y]

-- Contar as letra maiúsculas numa cadeia
contarMaiúsculas :: String -> Int
contarMaiúsculas xs = length [x | x<-xs, maiúscula x]

-- Converter um rácio numa percentagem 0--100
porcento :: Int -> Int -> Float
porcento num denom = (fromIntegral num / fromIntegral denom) * 100

-- Contar frequencias das letras num texto
freqs :: String -> [Float]
freqs xs =  [porcento (ocorrências x xs) n | x<-['A'..'Z']]
    where n = contarMaiúsculas xs

-- Calcular a medida estatística chi-quadrado
chiquad :: [Float] -> [Float] -> Float
chiquad os es = sum [((o-e)^2)/e | (o,e)<-zip os es]

-- Rotação circular de uma lista
rodar :: Int -> [a] -> [a]
rodar n xs = drop n xs ++ take n xs

-- Indices de ocorrências de um valor numa lista
indices :: Eq a => a -> [a] -> [Int]
indices x ys = [i | (i,y)<-zip [0..n] ys, x==y]
    where n = length ys - 1

-- Quebrar a cifra de César
quebrar :: String -> Int
quebrar xs = k
    where
      obs = freqs xs  -- frequência observadas das letras
      chitab = [chiquad (rodar k obs) tabelaPT | k<-[0..25]]
      k = head (indices (minimum chitab) chitab)

{- Alguns desafios
   autoria: Rogério Reis <rvr@dcc.fc.up.pt>
-}
-- espaços e pontuação preservados do texto original
desafio1 = "JCNXYJR XJRUWJ YWJX QFITX SZRF INXHZXXFT: T RJZ QFIT, T YJZ QFIT J T QFIT HTR WFEFT!"

-- espaços e pontuação removidos; letras agrupadas em blocos de 5
desafio2 = "QGZMA FQZTA YQPAP MYADF QEAZM ACGQD AQEFM DBDQE QZFQZ QEEQY AYQZF A"
