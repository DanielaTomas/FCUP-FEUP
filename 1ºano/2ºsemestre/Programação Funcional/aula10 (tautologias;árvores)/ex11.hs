data Arv a = Vazia | No a (Arv a) (Arv a)
             deriving Show

-- 1.
maisDir :: Arv a -> a
maisDir (No x _ Vazia) = x
maisDir (No _ _ dir) = maisDir dir

-- 2.
remover :: Ord a => a -> Arv a -> Arv a
remover x Vazia = Vazia -- não ocorre
remover x (No y Vazia dir) -- um descendente
| x == y = dir
remover x (No y esq Vazia) -- um descendente
| x == y = esq
remover x (No y esq dir) -- dois descendentes
| x < y = No y (remover x esq) dir
| x > y = No y esq (remover x dir)
| otherwise = let z = maisDir dir
              in No z esq (remover z dir)
