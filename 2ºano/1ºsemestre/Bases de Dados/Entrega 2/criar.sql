.mode columns
.headers on
Pragma Foreign_Keys = on;

drop table if exists Zoo;
create table Zoo(
  idZoo int PRIMARY KEY,
  nomeZoo text NOT NULL UNIQUE,
  lotacaoMaxima int CHECK(lotacaoMaxima >= 0),
  lotacaoAtual int CHECK(lotacaoAtual >= 0),
  numeroTelefone text NOT NULL UNIQUE CHECK(LENGTH (numeroTelefone = 9)),
  rua text NOT NULL,
  codigoPostal text,
  horaAbertura TIME,
  horaFecho TIME,
  numeroTotalAnimais int CHECK(numeroTotalAnimais >= 0),
  area int CHECK (area > 0),
  CHECK (horaFecho > horaAbertura),
  CHECK (lotacaoMaxima >= lotacaoAtual)
);

drop table if exists Visitante;
create table Visitante(
  nifVisitante text PRIMARY KEY CHECK(LENGTH (nifVisitante = 9)),
  nome text NOT NULL,
  idade int NOT NULL,
  numeroTelefone text NOT NULL UNIQUE CHECK(LENGTH (numeroTelefone = 9))
);

drop table if exists Bilhete;
create table Bilhete(
  codigo int PRIMARY KEY,
  horaEntrada TIME,
  dataBilhete DATE,
  preco float CHECK (preco >= 0),
  nifVisitante text references Visitante,
  idTipoBilhete int references TipoBilhete
);

drop table if exists TipoBilhete;
create table TipoBilhete(
  idTipoBilhete int PRIMARY KEY,
  tipoBilhete text NOT NULL
);

drop table if exists Servico;
create table Servico(
  idServico int PRIMARY KEY,
  nome text NOT NULL,
  numeroTelefone text NOT NULL UNIQUE CHECK (LENGTH (numeroTelefone = 9)),
  capacidade int,
  email text,
  horaAbertura TIME,
  horaFecho TIME,
  rua text NOT NULL,
  codigoPostal int,
  idZoo int references Zoo,
  CHECK (horaFecho > horaAbertura)
);

drop table if exists Hotel;
create table Hotel(
  idServico int PRIMARY KEY references Servico,
  preco float CHECK (preco >= 0)
);

drop table if exists Restaurante;
create table Restaurante(
  idServico int PRIMARY KEY references Servico,
  tipoRestaurante text,
  preco float CHECK (preco >= 0)
);

drop table if exists Animal;
create table Animal(
  idAnimal int PRIMARY KEY,
  nome text NOT NULL,
  idade int,
  nomeComum text NOT NULL,
  nomeCientifico text NOT NULL,
  dataChegadaZoo DATE,
  genero text,
  idZoo int references Zoo,
  idProgenitor references Animal
);

drop table if exists Funcionario;
create table Funcionario(
  nifFuncionario text PRIMARY KEY CHECK(LENGTH (nifFuncionario = 9)),
  nome text NOT NULL,
  rua text,
  codigoPostal int,
  dataNascimento DATE,
  email text UNIQUE,
  numeroTelefone text NOT NULL UNIQUE CHECK(LENGTH (numeroTelefone = 9)),
  idEspecialidade int references Especialidade,
  idZoo int references Zoo
);

drop table if exists Especialidade;
create table Especialidade(
  idEspecialidade int PRIMARY KEY,
  nome text NOT NULL
);

drop table if exists Sessao;
create table Sessao(
  idSessao int PRIMARY KEY,
  nome text NOT NULL,
  descricao text,
  idZoo int references Zoo
);

drop table if exists HorarioSessao;
create table HorarioSessao(
  idHorarioSessao int PRIMARY KEY,
  horaInicio TIME,
  horaFim TIME,
  CHECK (horaFim > horaInicio)
);

drop table if exists SessaoHorarioSessao;
create table SessaoHorarioSessao(
  idSessao int references Sessao,
  idHorarioSessao int references HorarioSessao,
  PRIMARY KEY (idSessao, idHorarioSessao)
);

drop table if exists Alimentacao;
create table Alimentacao(
  idAlimentacao int PRIMARY KEY,
  tipoAlimentacao text NOT NULL,
  quantidadeDisponivel int NOT NULL CHECK(quantidadeDisponivel >= 0)
);

drop table if exists Habitat;
create table Habitat(
  idHabitat int PRIMARY KEY,
  area int CHECK (area > 0),
  numeroAnimais int CHECK (numeroAnimais >= 0),
  tipoHabitat text NOT NULL,
  idZoo int references Zoo
);

drop table if exists VisitanteZoo;
create table VisitanteZoo(
  nifVisitante text references Visitante,
  idZoo int references Zoo,
  PRIMARY KEY (nifVisitante, idZoo)
);

drop table if exists FuncionarioAnimalSessao;
create table FuncionarioAnimalSessao(
  idAnimal int references Animal,
  nifFuncionario text references Funcionario,
  idSessao int references Sessao,
  PRIMARY KEY (idAnimal, nifFuncionario, idSessao)
);

drop table if exists AnimalHabitat;
create table AnimalHabitat(
  idAnimal int references Animal,
  idHabitat int references Habitat,
  PRIMARY KEY (idAnimal, idHabitat)
);

drop table if exists QuantidadeNecessaria;
create table QuantidadeNecessaria(
  idAnimal int references Animal,
  idAlimentacao int references Alimentacao,
  quantidadeNecessaria int NOT NULL CHECK (quantidadeNecessaria >= 0),
  PRIMARY KEY (idAnimal, idAlimentacao)
);
