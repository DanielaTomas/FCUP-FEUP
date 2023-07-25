{-
  O problema das 8 rainhas.
  Solução em Haskell baseada na de
  "Introduction to Functional Programming", Bird & Wadler, 1988
  Pedro Vasconcelos, 2021
-}


type Pos = (Int,Int)  -- posição (coluna, linha)

type Rainhas = [Int] -- lista de linhas de cada rainha

-- testar se duas rainhas se atacam
ataque :: Pos -> Pos -> Bool
ataque (x,y) (x',y') = x==x' ||   -- coluna
                       y==y' ||   -- linha
                       x-y == x'-y' || -- diagonais
                       x+y == x'+y'

-- testar segurança de uma nova posição
-- (não ataca qualquer rainha já colocada)
valida :: Int -> Rainhas -> Bool
valida y ys = all (not . ataque (x,y)) (zip [1..] ys)
  where x = 1+length ys

-- colocar n rainhas nas colunas 1..n
-- caso base: colocar zero rainhas (solução vazia)
-- caso recursivo:
-- acrescentar uma rainha a cada solução menor e testar segurança
-- a rainha número n colocada na coluna n
rainhas :: Int -> [Rainhas]
rainhas 0 = [[]]
rainhas n | n>0
  = [ys++[y] | ys<-rainhas (n-1), y<-[1..8], y`valida`ys]



---------------------------------------------------------------------------
-- vizualização de soluções
---------------------------------------------------------------------------

-- imprimir um tabuleiro
prettyBoard :: Rainhas -> String
prettyBoard ys
  = concat [show y ++ " " ++ line y ++ "\n"| y<-[8,7..1]]
    ++ footer
  where positions = zip [1..] ys
        line y = concat [bg x y (piece x y) | x<-[1..8]]
        footer = "  " ++ concat [show x ++ " " | x <- [1..8]]
        piece x y
          | (x,y)`elem`positions = blackQueen
          | otherwise            = empty
        bg x y txt
          | even (x+y) = bgGray ++ txt ++ bgDefault
          | otherwise  = txt

blackQueen = "\9819 "
empty      = "  "
bgGray     = "\ESC[47m"
bgDefault  = "\ESC[49m"

printBoard :: Rainhas -> IO ()
printBoard = putStrLn . prettyBoard

-- procurar e imprimir todas as soluções
main :: IO ()
main = sequence_
       [ do putStrLn ("Solução "++show i)
            printBoard ys
       | (i,ys) <- zip [1..] (rainhas 8)
       ]
