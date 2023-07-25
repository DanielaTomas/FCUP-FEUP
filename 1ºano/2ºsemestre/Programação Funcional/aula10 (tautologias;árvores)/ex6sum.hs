data Arv a = Vazia | No a (Arv a) (Arv a)
             deriving Show

sumArv :: Num a => Arv a -> a
sumArv Vazia = 0
sumArv (No a Vazia Vazia) = a
sumArv (No a esq dir) = a + sumArv esq + sumArv dir
