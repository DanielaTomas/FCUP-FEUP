import Log
--import Data.List
--import Data.Char
{-read: converte String em Inteiro;
words: para partir uma String em palavras;
unwords: para juntar palavras numa String
-}
parseMessage :: String -> LogEntry
parseMessage s | x == "E"  = LogMessage (tipo s) (read(head xss)) (xsss)
               | x == "I"  = LogMessage (tipo s) (read(head xs)) (unwords(xss))
               | x == "W"  = LogMessage (tipo s) (read(head xs)) (unwords(xss))
               | otherwise = Unknown s
               where x = head(words s)
                     xs = tail(words s)
                     xss = tail(xs)
                     xsss = unwords(tail(xss))

tipo :: String -> MessageType
tipo s | x == "E" = Error (read(head xs))
       | x == "I" = Info
       | otherwise = Warning
      where x = head(words s)
            xs = tail(words s)

parseLog :: String -> [LogEntry]
parseLog txt = map parseMessage (lines txt)

insert :: LogEntry -> MessageTree -> MessageTree
insert (Unknown _) Empty = Empty
insert (Unknown _) (Node x y z) = Node x y z
insert (LogMessage m1 t1 s1) Empty = Node (LogMessage m1 t1 s1) Empty Empty
insert (LogMessage m1 t1 s1) (Node (LogMessage m2 t2 s2) y z) | t1 < t2   = Node (LogMessage m2 t2 s2) (insert (LogMessage m1 t1 s1) y) z
                                                              | otherwise = Node (LogMessage m2 t2 s2) y (insert (LogMessage m1 t1 s1) z)


build :: [LogEntry] -> MessageTree -- construir uma árvore ordenada
build [] = Empty
build (x:xs) = insert x (build xs)

inOrder :: MessageTree -> [LogEntry]  -- listar mensagens por ordem // travessia por ordem infixa da árvore
inOrder Empty = []
inOrder (Node x y z) = esq ++ [x] ++ dir
                   where esq = inOrder y
                         dir = inOrder z

sortMessages :: [LogEntry] -> [LogEntry] -- ordenar mensagens
sortMessages msgs = inOrder (build msgs)
