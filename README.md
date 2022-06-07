<h1 align="center">Trabalho Arduino</h1>

<p align="center">O objetivo do trabalho é realizar uma comunicação síncrona entre duas plataformas Arduino.</p>

<p align="center">
    <a href="#contribuidores">Contribuidores</a> •
    <a href="#descricao-do-projeto">Descrição do Projeto</a> •
    <a href="#requisitos">Requisitos</a>
</p>

## Contribuidores

Bernardo Marques Costa - **11795551**\
João Victor Sene Araujo - **11796382**\
Pedro Augusto Ribeiro Gomes - **11819125**\
Rodrigo Assaf - **11795530**

## Descrição do Projeto
Neste trabalho, o Arduino emissor receberá um caractere pela sua porta serial (através do Serial Monitor da plataforma) e deverá enviar de forma serial e síncrona ao Arduino receptor, que imprimirá os caracteres recebidos em sua porta serial, exibindo para o usuário através do Serial Monitor. Os caracteres deverão ser transmitidos de acordo com o código ASCII (https://upload.wikimedia.org/wikipedia/commons/d/dd/ASCII-Table.svg)

## Requisitos

<ul>
  <li>A comunicação entre as duas plataformas deverá ser síncrona, ou seja, deve haver uma sincronização entre o emissor e o receptor através de um clock;</li>
  <li>A comunicação deverá implementar o controle de erros através de um bit de paridade;</li>
  <li>A comunicação deverá implementar um handshake simples entre o emissor e o receptor.</li>
</ul>
