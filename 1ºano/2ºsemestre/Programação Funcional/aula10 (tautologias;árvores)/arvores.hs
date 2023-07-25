{-
  Árvores binárias de pesquisa
  Pedro Vasconcelos, 2011-2021
-}


-- árvores binárias com nós de valores `a'
data Arv a = Vazia
           | No a (Arv a) (Arv a)
             deriving Show

-- listar os elementos da esquerda para a direita
listar :: Arv a -> [a]
listar Vazia = []
listar (No x esq dir) = listar esq ++ [x] ++ listar dir


-- verificar se uma árvore é *ordenada*, isto é:
-- o valor em cada nó é:
-- 1) maior que os valores na sub-árvore esquerda
-- 2) menor que os valores na sub-árvore direita
ordenada :: Ord a => Arv a -> Bool
ordenada arv = crescente (listar arv)
   where   -- verificar se uma lista está por ordem crescente
     crescente [] = True
     crescente [_] = True
     crescente (x:y:xs) = x<y && crescente (y:xs)


-- procurar um valor numa árvore de pesquisa
procura :: Ord a => a -> Arv a -> Bool
procura x Vazia = False
procura x (No y esq dir)
    | x==y  = True
    | x<y   = procura x esq
    | x>y   = procura x dir


-- inserir um elemento numa árvore de pesquisa
-- mantem a ordenação
inserir :: Ord  a => a -> Arv a -> Arv a
inserir x Vazia = No x Vazia Vazia
inserir x (No y esq dir)
    | x==y = No y esq dir
    | x<y  = No y (inserir x esq) dir
    | x>y  = No y esq (inserir x dir)



-- construir uma árvore equilibrada usando partição binária
-- pré-condição: a lista deve estar por ordem crescente
construir :: [a] -> Arv a
construir [] = Vazia
construir xs = No x (construir xs') (construir xs'')
    where xs'    = take n xs
          x:xs'' = drop n xs
          n      = length xs`div`2

-- remover um elemento duma árvore de pesquisa
remover :: Ord a => a -> Arv a -> Arv a
-- não encontrou
remover x Vazia  = Vazia
-- um descendente
remover x (No y Vazia dir)
    | x==y = dir
remover x (No y esq Vazia)
    | x==y = esq
-- dois descendentes
remover x (No y esq dir)
    | x<y  = No y (remover x esq) dir
    | x>y  = No y esq (remover x dir)
    | x==y = let z = maisEsq dir
             in No z esq (remover z dir)



-- valor mais à esquerda
-- (menor valor numa árvore ordenada)
maisEsq :: Arv a -> a
maisEsq (No x Vazia _) = x
maisEsq (No _ esq _)   = maisEsq esq



-- contar o número de nós
tamanho :: Arv a -> Int
tamanho Vazia          = 0
tamanho (No _ esq dir) = 1 + tamanho esq + tamanho dir

-- calcular a altura de uma árvore
-- maior comprimento da raiz até a uma folha
altura :: Arv a -> Int
altura Vazia          = 0
altura (No _ esq dir) = 1 + max (altura esq) (altura dir)


-- verificar se uma árvore é *equilibrada*, isto é:
-- em cada nó, a altura das sub-árvores direita
-- e esquerda difere no máximo de 1 unidade
equilibrada :: Arv a -> Bool
equilibrada Vazia = True
equilibrada (No _ esq dir)
    = abs (altura esq - altura dir)<=1 &&
      equilibrada esq &&
      equilibrada dir



-- programa principal
-- contar palavras da entrada-padrão sem repetições
main :: IO ()
main = do txt <- getContents
          let ws = words txt
          -- construir árvore de pesquisa
          let t = foldr inserir Vazia ws
          -- imprimir relatório
          putStrLn "Árvore binária simples:"
          putStrLn ("Tamanho = " ++ show (tamanho t))
          putStrLn ("Altura = " ++ show (altura t))
