PRAGMA foreign_keys=ON;
.mode columns
.headers on
.nullvalue NULL

/*
--8.1
select hostname,nome from Servidor s, Pessoa p
where s.idResponsavel = p.idPessoa and vulneravel = "sim";
*/
/*
--8.2
select hostname,b.descricao,p.nome from Servidor s, AplicacaoServidor ap, Aplicacao a, Pessoa p, Bug b
where s.idResponsavel = p.idPessoa
and ap.idServidor = s.idServidor
and ap.idAplicacao = a.idAplicacao
and b.idAplicacao = ap.idAplicacao
and vulnerabilidade = "sim"
order by hostname;
*/
/*
--8.4
select nome
 from Aplicacao,(select idAplicacao,count(*) as num1 from Bug group by idAplicacao) as T1
 where Aplicacao.idAplicacao = T1.idAplicacao and
  num1 in (select max(num2) from (select idAplicacao,count(idAplicacao) as num2 from Bug group by idAplicacao))
group by Aplicacao.idAplicacao;
*/
