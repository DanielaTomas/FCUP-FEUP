PRAGMA FOREIGN_KEYS=ON;

/* Apaga as tabelas se já existirem */
drop table if exists Estudante;
drop table if exists Amizade;
drop table if exists Curso;

/* Cria as tabelas */
create table Estudante(ID int PRIMARY KEY, nome text, curso int REFERENCES Curso(ID), anoCurricular int);
create table Amizade(ID1 int REFERENCES Estudante(ID), ID2 int REFERENCES Estudante(ID), PRIMARY KEY (ID1, ID2));

create table Curso (ID int PRIMARY KEY, nome text);

/* Insere dados nas tabelas */
insert into Curso values (1, 'MIEIC');
insert into Curso values (2, 'MIEEC');

insert into Estudante values (201101510, 'Ana Lopes', 1, 1);
insert into Estudante values (201101689, 'Gabriel Maria', 2, 1);
insert into Estudante values (201101381, 'Joao Nunes', 1, 1);
insert into Estudante values (201101709, 'Luis Goncalves', 2, 5);
insert into Estudante values (201101101, 'Maria Felisberta', 1, 2);
insert into Estudante values (201101782, 'Barbara Coutinho', 2, 2);
insert into Estudante values (201101468, 'Cristiano Rodrigo', 1, 2);
insert into Estudante values (201101641, 'Diogo Teixeira', 2, 2);
insert into Estudante values (201101247, 'Carla Silva', 1, 3);
insert into Estudante values (201101316, 'Joana Teixeira', 2, 3);
insert into Estudante values (201101911, 'Carlos Rodrigues', 1, 3);
insert into Estudante values (201101501, 'Sergio Carvalho', 2, 3);
insert into Estudante values (201101304, 'Mafalda Pimentel', 1, 4);
insert into Estudante values (201101025, 'Miguel Sampaio', 2, 4);
insert into Estudante values (201101934, 'Pedro Nunes', 1, 5);
insert into Estudante values (201101661, 'Cristina Ribeiro', 2, 5);

insert into Amizade values (201101689, 201101316);
insert into Amizade values (201101689, 201101304);
insert into Amizade values (201101510, 201101381);
insert into Amizade values (201101510, 201101689);
insert into Amizade values (201101689, 201101709);
insert into Amizade values (201101381, 201101247);
insert into Amizade values (201101709, 201101247);
insert into Amizade values (201101689, 201101782);
insert into Amizade values (201101782, 201101316);
insert into Amizade values (201101782, 201101304);
insert into Amizade values (201101101, 201101641);
insert into Amizade values (201101247, 201101911);
insert into Amizade values (201101247, 201101501);
insert into Amizade values (201101911, 201101501);
insert into Amizade values (201101501, 201101934);
insert into Amizade values (201101316, 201101934);
insert into Amizade values (201101934, 201101304);
insert into Amizade values (201101304, 201101661);
insert into Amizade values (201101661, 201101025);
insert into Amizade select ID2, ID1 from Amizade;

