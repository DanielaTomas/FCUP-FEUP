data Arv a = Vazia | No a (Arv a) (Arv a)
              deriving Show

nivel :: Int -> Arv a -> [a]
nivel _ Vazia = []
nivel 0 (No x _ _) = [x]
nivel n (No _ esq dir) = (nivel (n-1) esq) ++ (nivel (n-1) dir)
