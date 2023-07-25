data Arv a = Vazia | No a (Arv a) (Arv a)
           deriving Show

soma :: Num a => Arv a -> a
soma Vazia = 0
soma (No v esq dir) = v + (soma esq) + (soma dir)

foldtree :: (a -> b -> b -> b) -> b -> Arv a -> b
foldtree f n Vazia = n
foldtree f n (No v esq dir) = f v (foldtree f n esq) (foldtree f n dir) 
