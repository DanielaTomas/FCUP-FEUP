data Arv a = Vazia | No a (Arv a) (Arv a)
              deriving Show

listarDecr :: Arv a -> [a]
listarDecr Vazia = []
listarDecr (No x esq dir) = listarDecr dir ++ [x] ++ listarDecr esq
