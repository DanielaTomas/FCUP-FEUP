drop table if exists Aplicacao;
CREATE TABLE Aplicacao (
	idAplicacao integer primary key,
	nome text,
	descricao text
);

drop table if exists Servidor;
CREATE TABLE Servidor (
	idServidor integer primary key,
	idResponsavel integer references Aplicacao(idAplicacao),
	vulneravel text check (vulneravel in ("sim", "nao")) default "nao",
	hostname text
);

drop table if exists AplicacaoServidor;
CREATE TABLE AplicacaoServidor (
	idAplicacao integer references Aplicacao(idAplicacao),
	idServidor integer references Servidor(idServidor),
	primary key (idAplicacao, idServidor)
);

drop table if exists Pessoa;
CREATE TABLE Pessoa(
	idPessoa integer primary key, 
	nome text, 
	mail text unique
);

drop table if exists Bug;
CREATE TABLE Bug(
	idBug integer primary key, 
	idAplicacao integer references Aplicacao(idAplicacao), 
	idResponsavel integer references Pessoa(idPessoa), 
	descricao text, 
	prioridade integer check ( prioridade > 0 and prioridade < 6), 
	estado text check (estado in ("aberto", "fechado")), 
	vulnerabilidade check (vulnerabilidade in ("sim", "nao"))
);

drop table if exists Comentario;
CREATE TABLE Comentario(
	idComentario integer primary key, 
	idBug integer references Bug(idBug), 
	idAutor integer references Pessoa(idPessoa), 
	data date, 
	texto text
);

insert into aplicacao(nome, descricao) values ("redmine", "Gestao Entidades");
insert into aplicacao(nome, descricao) values ("sigarra", "Controlo de versoes");
insert into aplicacao(nome, descricao) values ("webmail", "Cliente de email web");
insert into aplicacao(nome, descricao) values ("mail", "Servico de email");

insert into pessoa(nome, mail) values ("Joao Almeida", "joao.almeida@cica.pt");
insert into pessoa(nome, mail) values ("Ana Goncalves", "ana.goncalves@cica.pt");
insert into pessoa(nome, mail) values ("Mario Manuel", "mario.manuel@cica.pt");

insert into servidor(idResponsavel, hostname, vulneravel) values (1, "porto", "sim");
insert into servidor(idResponsavel, hostname, vulneravel) values (1, "lisboa", "sim");
insert into servidor(idResponsavel, hostname) values (3, "evora");
insert into servidor(idResponsavel, hostname, vulneravel) values (2, "lagos", "sim");
insert into servidor(idResponsavel, hostname, vulneravel) values (3, "alu1", "sim");
insert into servidor(idResponsavel, hostname) values (1, "alu2");
insert into servidor(idResponsavel, hostname, vulneravel) values (2, "cica", "sim");


insert into AplicacaoServidor(idAplicacao, idServidor) values (1, 1);
insert into AplicacaoServidor(idAplicacao, idServidor) values (2, 2);
insert into AplicacaoServidor(idAplicacao, idServidor) values (3, 3);
insert into AplicacaoServidor(idAplicacao, idServidor) values (1, 4);
insert into AplicacaoServidor(idAplicacao, idServidor) values (2, 5);
insert into AplicacaoServidor(idAplicacao, idServidor) values (2, 6);
insert into AplicacaoServidor(idAplicacao, idServidor) values (1, 5);

insert into bug(idAplicacao, idResponsavel, descricao, prioridade, estado, vulnerabilidade) values (1, 1, "code injection na pagina de login", 1, "aberto", "sim");

insert into bug(idAplicacao, idResponsavel, descricao, prioridade, estado, vulnerabilidade) values (2, 3, "falha seguranca", 1, "aberto", "sim");

insert into bug(idAplicacao, idResponsavel, descricao, prioridade, estado, vulnerabilidade) values (1, 3, "Botao na pagina de login esta errado", 5, "aberto", "nao");

insert into comentario (idBug, idAutor, data, texto) values (1, 1, "2013-01-01", "Detetado code injection no form de login");
insert into comentario (idBug, idAutor, data, texto) values (1, 2, "2013-01-02", "Necessario validar o campo");

