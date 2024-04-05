// Enunciat:Un programa que te ayude a gestionar la lista de la compra.
// Si el producto que has insertado ya lo habías aplicado, tiene que modificarlo 
// aunque las mayúsculas o minúsculas no coincidan. Tiene que permitir 
// visualizar e insertar.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Estructura per representar un producte
struct Producte {
    std::string nom;
    int quantitat;
};

// Funcio per buscar producte a la llista pel nom (ignorant majuscules/minuscules)
bool buscarProducte(const std::vector<Producte>& llista, const std::string& nom) {
    for (const auto& producte : llista) {
        if (producte.nom.size() == nom.size()) {
            bool coincideixen = true;
            for (size_t i = 0; i < producte.nom.size(); ++i) {
                if (tolower(producte.nom[i]) != tolower(nom[i])) {
                    coincideixen = false;
                    break;
                }
            }
            if (coincideixen) {
                return true;
            }
        }
    }
    return false;
}

// Funcio per inserir producte a la llista o modificar si existeix
void inserirModificarProducte(std::vector<Producte>& llista, const std::string& nom, int quantitat) {
    for (auto& producte : llista) {
        if (producte.nom.size() == nom.size()) {
            bool coincideixen = true;
            for (size_t i = 0; i < producte.nom.size(); ++i) {
                if (tolower(producte.nom[i]) != tolower(nom[i])) {
                    coincideixen = false;
                    break;
                }
            }
            if (coincideixen) {
                // Si producte existeix, donar opcions per sumar o canviar num
                std::cout << "El producte ja existeix a la llista:\n";
                std::cout << "1. Sumar a la quantitat actual\n";
                std::cout << "2. Canviar la quantitat\n";
                int opcio;
                std::cout << "Seleccioneu una opció: ";
                std::cin >> opcio;
                switch (opcio) {
                case 1:
                    producte.quantitat += quantitat;
                    std::cout << "S'ha sumat a la quantitat actual.\n";
                    break;
                case 2:
                    producte.quantitat = quantitat;
                    std::cout << "S'ha canviat la quantitat.\n";
                    break;
                default:
                    std::cout << "Opció no vàlida. No s'ha fet cap modificació.\n";
                    break;
                }
                return;
            }
        }
    }
    // Si el producte no existeix, l'inserim a la llista
    llista.push_back({ nom, quantitat });
}

// Funcio per mostrar llista compra
void mostrarLlistaCompra(const std::vector<Producte>& llista) {
    std::cout << "Llista de la compra:\n";
    for (const auto& producte : llista) {
        std::cout << producte.nom << " - Quantitat: " << producte.quantitat << "\n";
    }
}

int main() {
    std::vector<Producte> llistaCompra;

    // Menú
    int opcio;
    do {
        std::cout << "\n1. Inserir/modificar producte\n";
        std::cout << "2. Mostrar llista de la compra\n";
        std::cout << "3. Sortir\n";
        std::cout << "Seleccioneu una opció: ";
        std::cin >> opcio;

        switch (opcio) {
        case 1: {
            std::string nom;
            int quantitat;
            std::cout << "Nom del producte: ";
            std::cin >> nom;
            std::cout << "Quantitat: ";
            std::cin >> quantitat;
            inserirModificarProducte(llistaCompra, nom, quantitat);
            break;
        }
        case 2:
            mostrarLlistaCompra(llistaCompra);
            break;
        case 3:
            std::cout << "Sortint del programa.\n";
            break;
        default:
            std::cout << "Opció no vàlida. Intenteu-ho de nou.\n";
            break;
        }
    } while (opcio != 3);

    return 0;
}


