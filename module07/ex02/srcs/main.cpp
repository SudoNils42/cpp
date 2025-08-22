/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:15:43 by nbonnet           #+#    #+#             */
/*   Updated: 2025/08/22 15:41:55 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Array.hpp"

int main() {  // Début de la fonction main, point d'entrée. Retourne int (0 pour succès).
    std::cout << "Test 1: Constructeur par defaut (vide)" << std::endl;  // Affiche un titre pour clarté, aidant à identifier les sections de test.
    Array<int> empty;  // Crée un Array vide avec constructeur par défaut. Pourquoi : Teste si _data == 0 et _len == 0.
    std::cout << "Taille : " << empty.size() << std::endl;  // Appelle size() const, vérifie 0.
    
    try {  // Bloc try pour capturer les exceptions. Pourquoi : Teste les cas tricky comme l'accès hors bornes.
        empty[0];  // Essaie d'accéder à un élément dans un tableau vide. Devrait throw std::exception.
    } catch (std::exception& e) {  // Catch l'exception. std::exception est la base en C++98.
        std::cout << "Exception capturee (attendue) : acces hors bornes" << std::endl;  // Affiche pour confirmer le comportement.
    }

    std::cout << "Test 2: Constructeur avec taille (initialisation par defaut)" << std::endl;
    Array<int> arr(3);  // Crée un Array de 3 int avec valeurs par défaut (0). Pourquoi : Teste allocation et initialisation.
    std::cout << "Taille : " << arr.size() << std::endl;  // Vérifie size() == 3.
    std::cout << "Valeurs par defaut : " << arr[0] << ", " << arr[1] << ", " << arr[2] << std::endl;  // Accède via operator[], vérifie 0,0,0.

    std::cout << "Test 3: Modification et acces" << std::endl;
    arr[0] = 42; arr[1] = 21; arr[2] = 10;  // Modifie via operator[] non-const. Pourquoi : Teste l'écriture.
    std::cout << "Apres modification : " << arr[0] << ", " << arr[1] << ", " << arr[2] << std::endl;  // Vérifie les changements.

    std::cout << "Test 4: Constructeur par copie (copie profonde)" << std::endl;
    Array<int> copy(arr);  // Crée une copie. Pourquoi : Teste si copie profonde (allocation séparée).
    std::cout << "Taille copie : " << copy.size() << std::endl;  // Vérifie size() == 3.
    std::cout << "Valeurs copie : " << copy[0] << ", " << copy[1] << ", " << copy[2] << std::endl;  // Vérifie valeurs copiées.
    arr[0] = 100;  // Modifie original. Pourquoi : Teste indépendance (copie profonde).
    std::cout << "Original modifie : " << arr[0] << std::endl;  // 100.
    std::cout << "Copie inchangee : " << copy[0] << std::endl;  // Doit rester 42.

    std::cout << "Test 5: Operateur d'affectation (copie profonde)" << std::endl;
    Array<int> assign(2);  // Crée un Array de 2 éléments.
    assign = arr;  // Affecte. Pourquoi : Teste operator=, libération ancienne mémoire et copie.
    std::cout << "Taille apres affectation : " << assign.size() << std::endl;  // Doit être 3.
    std::cout << "Valeurs apres affectation : " << assign[0] << ", " << assign[1] << ", " << assign[2] << std::endl;  // 100,21,10.
    arr[1] = 200;  // Modifie original. Pourquoi : Teste indépendance.
    std::cout << "Original modifie : " << arr[1] << std::endl;  // 200.
    std::cout << "Affecte inchange : " << assign[1] << std::endl;  // 21.

    std::cout << "Test 6: Auto-affectation" << std::endl;
    assign = assign;  // Affecte à soi-même. Pourquoi : Teste if (this != &rhs) pour éviter destruction inutile.
    std::cout << "Taille apres auto-affectation : " << assign.size() << std::endl;  // Toujours 3.

    std::cout << "Test 7: Acces hors bornes" << std::endl;
    try {
        arr[3];  // Accès invalide. Pourquoi : Teste throw dans operator[].
    } catch (std::exception& e) {
        std::cout << "Exception capturee (attendue) : hors bornes" << std::endl;
    }

    std::cout << "Test 8: Version const" << std::endl;
    const Array<int> constArr(arr);  // Crée un Array const via copie. Pourquoi : Teste operator[] const.
    std::cout << "Acces const : " << constArr[0] << std::endl;  // Utilise la version const.
    std::cout << "Taille const : " << constArr.size() << std::endl;  // size() const.

    std::cout << "Test 9: Cas tricky - Tableau vide copie/affectation" << std::endl;
    Array<int> emptyCopy(empty);  // Copie d'un vide. Pourquoi : Teste size==0, pas de crash.
    std::cout << "Taille copie vide : " << emptyCopy.size() << std::endl;  // 0.
    Array<int> emptyAssign(1);  // Crée non-vide.
    emptyAssign = empty;  // Affecte vide. Pourquoi : Teste redimension à 0, libération.
    std::cout << "Taille apres affectation vide : " << emptyAssign.size() << std::endl;  // 0.

    std::cout << "Test 10: Generique avec autres types" << std::endl;
    Array<std::string> strArr(2);  // Test avec string. Pourquoi : Vérifie généricité.
    strArr[0] = "hello"; strArr[1] = "world";
    std::cout << "String Array : " << strArr[0] << " " << strArr[1] << std::endl;

    return 0;  // Fin de main, retourne 0 pour succès.
}
// int main() {
//     Array<int> IntTabEmpty();
//     Array<int> IntTab(3);
//     IntTab[0] = 1;
//     IntTab[1] = 2;
//     IntTab[2] = 3;
    
//     Array<char> CharTabEmpty();
//     Array<char> CharTab(3);
//     CharTab[0] = 'a';
//     CharTab[1] = 'b';
//     CharTab[2] = 'c';
    
//     Array<std::string> StringTab(2);
//     StringTab[0] = "Hello";
//     StringTab[1] = "wolrd!";
    
//     return 0;
// }