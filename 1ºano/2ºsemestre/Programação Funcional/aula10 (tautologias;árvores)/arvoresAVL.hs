{-
  Árvores equilibradas AVL (Adelson-Velski e Landis)
  Versão ineficiente (serve como especificação)

  Pedro Vasconcelos, 2021
  pbv@dcc.fc.up.pt
-}
-- a declaração é identica às árvores de pesquisa simples
data Arv a
  = Vazia
  | No a (Arv a) (Arv a)
  deriving (Eq, Show)

-- listar os elementos da esquerda para a direita
listar :: Arv a -> [a]
listar Vazia = []
listar (No x esq dir) = listar esq ++ [x] ++ listar dir

-- verificar se uma árvore é *ordenada*, isto é:
-- o valor em cada nó é maior que os valores na sub-árvore esquerda
-- e menor que os valores na sub-árvore direita
ordenada :: Ord a => Arv a -> Bool
ordenada t = crescente (listar t)
      -- verificar se uma lista está ordenada
  where
    crescente [] = True
    crescente [_] = True
    crescente (x:y:ys) = x<y && crescente (y:ys)

-- contar o *número de nós*
tamanho :: Arv a -> Int
tamanho Vazia = 0
tamanho (No _ esq dir) = 1 + tamanho esq + tamanho dir

-- calcular a *altura* da árvore
altura :: Arv a -> Int
altura Vazia = 0
altura (No _ esq dir) = 1 + max (altura esq) (altura dir)

-- calcular o *desvio*
-- diferença entre altura da esquerda e da direita
desvio :: Arv a -> Int
desvio Vazia = 0
desvio (No _ esq dir) = altura esq - altura dir

-- verificar se uma árvore é *equilibrada*
-- em cada nó, o desvio é  -1, 0 ou 1
equilibrada :: Arv a -> Bool
equilibrada Vazia = True
equilibrada (No _ esq dir) 
  = abs (altura esq - altura dir) <= 1 &&
    equilibrada esq &&
    equilibrada dir

-- * rotações simples
rodarEsq, rodarDir :: Arv a -> Arv a
rodarEsq (No x t1 (No y t2 t3)) = No y (No x t1 t2) t3
rodarEsq t = t -- outros casos

rodarDir (No x (No y t1 t2) t3) = No y t1 (No x t2 t3)
rodarDir t = t -- outros casos

-- * rotações compostas
-- efectua uma ou duas rotações conforme o desvio do nó interior
corrigeEsq, corrigeDir :: Arv a -> Arv a
corrigeEsq (No x t1 t2)
  | desvio t2 == 1 = rodarEsq (No x t1 (rodarDir t2))
  | otherwise = rodarEsq (No x t1 t2)
corrigeEsq t = t -- outros casos

corrigeDir (No x t1 t2)
  | desvio t1 == -1 = rodarDir (No x (rodarEsq t1) t2)
  | otherwise = rodarDir (No x t1 t2)
corrigeDir t = t -- outros casos

-- * re-equilibrar a árvore
reequilibrar :: Arv a -> Arv a
reequilibrar arv
  | d == 2 = corrigeDir arv -- para a direita
  | d == -2 = corrigeEsq arv -- para a esquerda
  | otherwise = arv
  where
    d = desvio arv

-- * inserção (mantendo a árvore equilibrada)
inserirAVL :: Ord a => a -> Arv a -> Arv a
inserirAVL x Vazia = No x Vazia Vazia
inserirAVL x (No y esq dir)
  | x == y --  valor já ocorre
   = No y esq dir
  | x < y -- inserir à esquerda
   = reequilibrar (No y (inserirAVL x esq) dir)
  | x > y -- inserir à direita
   = reequilibrar (No y esq (inserirAVL x dir))

-- * remoção (mantendo a árvore equilibrada)
-- exercício das práticas
removerAVL :: Ord a => a -> Arv a -> Arv a
removerAVL = undefined

-- programa principal
-- contar palavras da entrada padrão sem repetições
main :: IO ()
main = do
  txt <- getContents
  let ws = words txt
          -- construir uma árvore binária
  let t = foldr inserirAVL Vazia ws
          -- imprimir relatório
  putStrLn "Árvore AVL:"
  putStrLn ("Tamanho = " ++ show (tamanho t))
  putStrLn ("Altura = " ++ show (altura t))
