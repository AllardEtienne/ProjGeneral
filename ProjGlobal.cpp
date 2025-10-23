// ProjGlobal.cpp : définit le point d'entrée de l'application.
//

#include "ProjGlobal.h"
#include "ParceDecimal.h"


// Main function demonstrating the use of parse_decimal
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::println("Usage: {} <float_value>", argv[0]);
        return 1;
    }

    auto number = common::parse_decimal(argv[1]);
    if (number.has_value()) {
        std::println("Received parameter : {:.2f}", number.value());
    }
    else {
        std::println("{}", number.error());
        return 1;
    }
    return 0;
}
