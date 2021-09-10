#ifndef NODO_H
#define NODO_H

#include "ListaEncadeada.h"
#include <stdlib.h>
#include <queue>

using namespace std;

template<typename T>
struct Nodo
{
	Nodo * _filhoEsquerda;
	Nodo * _filhoDireita;
	T* _dado;
};

template<typename T>
Nodo<T>* criarNodo(T* dado)
{
	Nodo<T>* nodo = (Nodo<T> *)calloc(1, sizeof(Nodo<T>));
	nodo->_dado = dado;
	nodo ->_filhoEsquerda = NULL;
	nodo->_filhoDireita = NULL;

	return nodo;
}

/**
 * @brief Adiciona um dado à árvore 
 * @param raiz ponteiro para o ponteiro da raiz da árvore
 * @param dado ponteiro para dado a ser inserido
 * @return novo nodo que contém dado e que foi adicionado a árvore
 */
template<typename T>
Nodo<T>* adicionar(Nodo<T>** praiz, T* dado)
{
    Nodo<T>* raiz = *praiz;
    Nodo<T>* aux = nullptr;

	if (raiz->_dado == nullptr)
	{
		raiz->_filhoEsquerda = nullptr;
		raiz->_filhoDireita = nullptr;
		raiz->_dado = dado;

		return raiz;
	}
	else if (*dado < *raiz->_dado)
	{
		if (raiz->_filhoEsquerda == nullptr)
		{
			Nodo<T>* novo = criarNodo(dado);
			raiz->_filhoEsquerda = novo;
			aux = novo;
		}
		else
		{
			aux = adicionar(&raiz->_filhoEsquerda, dado);
		}
	}
	else
	{
		if (raiz->_filhoDireita == nullptr)
		{
			Nodo<T>* novo = criarNodo(dado);
			raiz->_filhoDireita = novo;
			aux = novo;
		}
		else
		{
			aux = adicionar(&raiz->_filhoDireita, dado);
		}
	}
	return aux;
}

/**
 * @brief Percorre árvore em pré-ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em pré-ordem
 */
template<typename T>
void preOrdem(Nodo<T>* raiz, ListaEncadeada* lista)
{
	if (raiz != NULL and raiz->_dado != NULL)
	{
		adicionaNoFim(lista, raiz->_dado);
		preOrdem(raiz->_filhoEsquerda, lista);
		preOrdem(raiz->_filhoDireita, lista);
	}
}

/**
 * @brief Percorre árvore em ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em ordem
 */
template<typename T>
void emOrdem(Nodo<T>* raiz, ListaEncadeada* lista)
{
    if (raiz != NULL and raiz->_dado != NULL)
    {
    	emOrdem(raiz->_filhoEsquerda, lista);
    	adicionaNoFim(lista, raiz->_dado);
    	emOrdem(raiz->_filhoDireita, lista);
    }
}

/**
 * @brief Percorre árvore em pós-ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em pós-ordem
 */
template<typename T>
void posOrdem(Nodo<T>* raiz, ListaEncadeada* lista)
{
    if (raiz != NULL and raiz->_dado != NULL)
    {
    	posOrdem(raiz->_filhoEsquerda, lista);
    	posOrdem(raiz->_filhoDireita, lista);
    	adicionaNoFim(lista, raiz->_dado);
    }
}

//NAO MODIFIQUE ESTA FUNCAO
template<typename T>
Nodo<T>* getNodo(Nodo<T>* raiz, T dado)
{
	while(raiz != NULL && dado != *raiz->_dado)
	{
		if(dado < *raiz->_dado)
		{
			raiz = raiz->_filhoEsquerda;
		}
		else 
		{
			raiz = raiz->_filhoDireita;
		}
	}
	return raiz;
}

template<typename T>
Nodo<T>* getMin(Nodo<T> *raiz)
{
	if (raiz == nullptr)
	{
		return raiz;
	}
	else 
	{
		while (raiz->_filhoEsquerda != NULL)
		{
			raiz = raiz->_filhoEsquerda;
		}

		return raiz;
	}
}

template<typename T>
Nodo<T>* getPaidominimo(Nodo<T> *raiz)
{
	Nodo<T>* pai = nullptr;
	if (raiz == nullptr)
	{
		return raiz;
	}
	else 
	{
		while (raiz->_filhoEsquerda != NULL)
		{
			pai = raiz;
			raiz = raiz->_filhoEsquerda;
		}

		return pai;
	}
}

/**
 * @brief Remove um dado à árvore
 * @param raiz ponteiro para raiz da árvore
 * @param dado dado a ser inserido
 * @return a raiz da árvore passada como parâmetro
 */
template<typename T>
T* remover(Nodo<T>** praiz, T dado)
{
	Nodo<T>* raiz = *praiz;
	Nodo<T>* papis = nullptr;
	Nodo<T>* minimo = nullptr;
	T* retorno;

	while(raiz != nullptr and dado != *raiz->_dado)
	{
		papis = raiz;
		if (dado < *raiz->_dado)
		{
			raiz = raiz->_filhoEsquerda;
		}
		else
		{
			raiz = raiz->_filhoDireita;
		}
	}
	if (raiz == nullptr)
	{
		return nullptr;
	}
	else
	{
		retorno = raiz->_dado;
	}

	minimo = getMin(raiz->_filhoDireita);
	
	if (minimo == nullptr) //se a raiz é o mínimo da subárvore
	{
		if (papis == nullptr) //se eu quero deletar a raiz principal
		{
			*praiz = raiz->_filhoDireita;
			retorno = raiz->_dado;
			free(raiz);
		}
		else
		{
			if (*raiz->_dado < *papis->_dado)
			{
				papis->_filhoEsquerda = nullptr;
			}
			else
			{
				papis->_filhoDireita = nullptr;
			}
			free(raiz);
		}
	}
	else
	{
		T* aux = minimo->_dado;

		remover(&raiz, *aux);

		raiz->_dado = aux;
	}

	return retorno;
}

/**
 * @brief Desaloca todos os nodos de uma árvore. Os dados não são desalocados.
 * @param raiz ponteiro para raiz da árvore
 */
template<typename T>
void destruir2(Nodo<T>* raiz)
{
	while (raiz != NULL)
	{
		Nodo<T>* aux = raiz;
		if (raiz->_filhoDireita == NULL and raiz->_filhoEsquerda == NULL)
		{
			free(raiz);

			raiz = NULL;
		}
		else if (raiz->_filhoDireita == NULL)
		{
			raiz = raiz->_filhoEsquerda;

			free(aux);
		}
		else if (raiz->_filhoEsquerda == NULL)
		{
			raiz = raiz->_filhoDireita;

			free(aux);
		}
	}
	return;
}

template<typename T>
void destruir(Nodo<T>* raiz)
{
	if (raiz != nullptr)
	{
		if (raiz->_filhoEsquerda != nullptr)
		{
			destruir(raiz->_filhoEsquerda);
		}
		if (raiz->_filhoDireita != nullptr)
		{
			destruir(raiz->_filhoDireita);
		}

		free(raiz);
	}
}

#endif /* NODO_H */