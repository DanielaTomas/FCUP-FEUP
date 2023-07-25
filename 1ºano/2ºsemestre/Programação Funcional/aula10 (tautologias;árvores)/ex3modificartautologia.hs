import Tautologias
{-
equiv :: Prop -> Prop -> Bool
equiv p q = if tautologia (Conj (Impl p q) (Impl q p)) then True
            else False

tautologia :: Prop -> Bool
tautologia p = and [valor s p | s<-atribs p] -}
