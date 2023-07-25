import Tautologias

satisfaz :: Prop -> Bool
satisfaz p = or [valor s p | s<-atribs p]
