#include "gtest/gtest.h"
#include "Nodo.h"

//voce pode modificar este arquivo à vontade

TEST(ArvoreBinariaBuscaTest,PreOrdem){
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    Nodo<int>* raiz = (Nodo<int>*) calloc(1,sizeof(Nodo<int>));
    adicionar(&raiz, &e5);
    adicionar(&raiz, &e3);
    adicionar(&raiz, &e7);
    adicionar(&raiz, &e2);
    adicionar(&raiz, &e4);
    adicionar(&raiz, &e6);
    adicionar(&raiz, &e9);

    ListaEncadeada* lista = iniciaListaEncadeada();
    preOrdem(raiz, lista);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e5);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e3);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e2);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e4);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e7);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e6);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e9);

    destruir(raiz);
    free(lista);
}


TEST(ArvoreBinariaBuscaTest,EmOrdem){
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    Nodo<int>* raiz = (Nodo<int>*) calloc(1,sizeof(Nodo<int>));
    adicionar(&raiz, &e5);
    adicionar(&raiz, &e3);
    adicionar(&raiz, &e7);
    adicionar(&raiz, &e2);
    adicionar(&raiz, &e4);
    adicionar(&raiz, &e6);
    adicionar(&raiz, &e9);

    ListaEncadeada* lista = iniciaListaEncadeada();
    emOrdem(raiz, lista);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e2);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e3);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e4);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e5);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e6);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e7);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e9);

    destruir(raiz);
    free(lista);
}

TEST(ArvoreBinariaBuscaTest,PosOrdem){
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    Nodo<int>* raiz = (Nodo<int>*) calloc(1,sizeof(Nodo<int>));
    Nodo<int>* novo = nullptr;
    
    novo = adicionar(&raiz, &e5);
    ASSERT_EQ(*novo->_dado, 5);
    ASSERT_EQ(novo->_filhoDireita, nullptr);
    ASSERT_EQ(novo->_filhoEsquerda, nullptr);

    novo = adicionar(&raiz, &e3);
    ASSERT_EQ(*novo->_dado, 3);
    ASSERT_EQ(novo->_filhoDireita, nullptr);
    ASSERT_EQ(novo->_filhoEsquerda, nullptr);

    novo = adicionar(&raiz, &e7);
    ASSERT_EQ(*novo->_dado, 7);
    ASSERT_EQ(novo->_filhoDireita, nullptr);
    ASSERT_EQ(novo->_filhoEsquerda, nullptr);

    novo = adicionar(&raiz, &e2);
    ASSERT_EQ(*novo->_dado, 2);
    ASSERT_EQ(novo->_filhoDireita, nullptr);
    ASSERT_EQ(novo->_filhoEsquerda, nullptr);

    novo = adicionar(&raiz, &e4);
    ASSERT_EQ(*novo->_dado, 4);
    ASSERT_EQ(novo->_filhoDireita, nullptr);
    ASSERT_EQ(novo->_filhoEsquerda, nullptr);

    novo = adicionar(&raiz, &e6);
    ASSERT_EQ(*novo->_dado, 6);
    ASSERT_EQ(novo->_filhoDireita, nullptr);
    ASSERT_EQ(novo->_filhoEsquerda, nullptr);

    novo = adicionar(&raiz, &e9);
    ASSERT_EQ(*novo->_dado, 9);
    ASSERT_EQ(novo->_filhoDireita, nullptr);
    ASSERT_EQ(novo->_filhoEsquerda, nullptr);

    ListaEncadeada* lista = iniciaListaEncadeada();
    posOrdem(raiz, lista);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e2);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e4);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e3);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e6);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e9);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e7);
    ASSERT_EQ(*(int*)retiraDoInicio(lista),e5);

    destruir(raiz);
    free(lista);
} 

TEST(ArvoreBinariaBuscaTest,GetNodo){
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    Nodo<int>* raiz = (Nodo<int>*) calloc(1,sizeof(Nodo<int>));
    adicionar(&raiz, &e5);
    adicionar(&raiz, &e3);
    adicionar(&raiz, &e7);
    adicionar(&raiz, &e2);
    adicionar(&raiz, &e4);
    adicionar(&raiz, &e6);
    adicionar(&raiz, &e9);

    Nodo<int> *nodo;

    nodo = getNodo(raiz,9);
    ASSERT_EQ(nodo->_filhoEsquerda, nullptr);
    ASSERT_EQ(nodo->_filhoDireita, nullptr);
    ASSERT_EQ(*nodo->_dado, 9);

    nodo = getNodo(raiz,7);
    ASSERT_NE(nodo->_filhoEsquerda, nullptr);
    ASSERT_NE(nodo->_filhoDireita, nullptr);
    ASSERT_EQ(*nodo->_dado, 7);
    destruir(raiz);   
}

TEST(ArvoreBinariaBuscaTest,Remover){
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;
    int* dadoRemovido;

    Nodo<int>* raiz = (Nodo<int>*) calloc(1,sizeof(Nodo<int>));
    adicionar(&raiz, &e5);
    adicionar(&raiz, &e3);
    adicionar(&raiz, &e7);
    adicionar(&raiz, &e2);
    adicionar(&raiz, &e4);
    adicionar(&raiz, &e6);
    adicionar(&raiz, &e9);

    Nodo<int> *nodo;

    //Testa remover chave inexistente
    //dadoRemovido = remover(raiz, 10);
    //ASSERT_EQ(dadoRemovido, nullptr);

    //Testa remover folha
    remover(&raiz, 9);
    ASSERT_EQ(getNodo(raiz,9), nullptr);
    nodo = getNodo(raiz, 7);
    ASSERT_EQ(nodo->_filhoDireita, nullptr);
    
    //Testa remover folha
    remover(&raiz, 6);
    ASSERT_EQ(getNodo(raiz,6), nullptr);
    nodo = getNodo(raiz, 7);
    ASSERT_EQ(nodo->_filhoEsquerda, nullptr);
    ASSERT_EQ(nodo->_filhoDireita, nullptr);
    
    //Testa remover raiz
    adicionar(&raiz, &e6);
    adicionar(&raiz, &e9);
    remover(&raiz, 5);
    ASSERT_EQ(getNodo(raiz,5), nullptr);
    nodo = getNodo(raiz, 6);
    ASSERT_EQ(nodo->_filhoDireita,getNodo(raiz,7));
    
    //Testa remover nodo com filhoDireita sem descendente a direita
    adicionar(&raiz, &e5);
    nodo = getNodo(raiz, 4);
    ASSERT_EQ(nodo->_filhoDireita, getNodo(raiz,5));
    remover(&raiz, 3);
    ASSERT_EQ(getNodo(raiz,3), nullptr);
    ASSERT_EQ(*raiz->_filhoEsquerda->_dado,4);
    ASSERT_EQ(*raiz->_filhoEsquerda->_filhoDireita->_dado,5);
    ASSERT_EQ(raiz->_filhoEsquerda->_filhoDireita->_filhoDireita,nullptr);
    ASSERT_EQ(raiz->_filhoEsquerda->_filhoDireita->_filhoEsquerda,nullptr);
    ASSERT_EQ(*raiz->_filhoEsquerda->_filhoEsquerda->_dado,2);

    
    destruir(raiz);   


}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
