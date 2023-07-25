module Tautologias where
import Data.List (nub)  -- remover repetidos
-- tipo para expressões proposicionais
data Prop = Const Bool        -- constantes
          | Var Char          -- variáveis
          | Neg Prop          -- negação
          | Conj Prop Prop    -- conjunção
          | Disj Prop Prop    -- disjunção
          | Impl Prop Prop    -- implicação
            deriving (Eq,Show)

-- listas de associações
type Assoc ch v = [(ch,v)]

-- encontrar o valor associado a uma chave
-- parcial: erro se a chave não ocorre
find :: Eq ch => ch -> Assoc ch v -> v
find x assocs = head [v | (x',v)<-assocs, x==x']

-- atribuições de valores a variaveis
type Atrib = Assoc Char Bool

-- calcular o valor duma proposição
valor :: Atrib -> Prop -> Bool
valor s (Const b) = b
valor s (Var x)    = find x s
valor s (Neg p)    = not (valor s p)
valor s (Conj p q) = valor s p && valor s q
valor s (Disj p q) = valor s p || valor s q
valor s (Impl p q) = not (valor s p) || valor s q

-- gerar todas sequências de `n' boleanos
bits :: Int -> [[Bool]]
bits 0 = [[]]
bits n = [b:bs | bs<-bits (n-1), b<-[False,True]]

-- todas as atribuições às variáveis duma proposição
atribs :: Prop -> [Atrib]
atribs p = map (zip vs) (bits (length vs))
    where vs = nub (vars p)  -- variáveis sem repetições

-- coleciona todas as variáveis duma proposição
vars :: Prop -> [Char]
vars (Const _)   =  []
vars (Var x)     =  [x]
vars (Neg p)     =  vars p
vars (Conj p q)  =  vars p ++ vars q
vars (Disj p q)  =  vars p ++ vars q
vars (Impl p q)  =  vars p ++ vars q

-- verificar se é taulogia
tautologia :: Prop -> Bool
tautologia p = and [valor s p | s<-atribs p]
