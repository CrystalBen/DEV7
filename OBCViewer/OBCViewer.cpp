#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <script.obc> <output.txt>\n" << std::endl;
        printf("Supported games:\n");
        printf(" * Adibou 3\n");
        printf(" * Adi 5\n");
        printf(" * Adibou presente series\n");
        printf(" * Adiboud'chou series\n");
        printf(" * Le Pays des pierres magiques\n\n");
        printf("<script.obc>\n\t .obc script to view\n\n");
        printf("<output.txt>\n\tlocate where OBCViewer should store the viewable text of the OBC Script\n\n");
        printf("Credits:\n");
        printf("BJNFNE (main Developer)\n");
        printf("rzil (BLooperZ) (Thanks for helping out)\n\n");
        return 1;
    }

    std::string inputOBC = argv[1];
    std::string outputOBC = argv[2];

    // Check if the input file is an OBC Script.
    std::filesystem::path inputFile(inputOBC);
    if (inputFile.extension() != ".obc") {
        std::cerr << "Error: This File is not an OBC Script!\n" << std::endl;
        return 1;
    }

// Use the OBC Script for Input
    std::ifstream OBCInput(inputOBC);

    if (!OBCInput) {
        std::cerr << "Error: Unable to find OBC Script." << std::endl;
        return 1;
    }

    std::string searchEntrypoint = "OBC Copyright 1999";
    std::string line;

    // Search for the Entrypoint in the Script
    bool found = false;
    while (std::getline(OBCInput, line)) {
        if (line.find(searchEntrypoint) != std::string::npos) {
            found = true;
            break;
        }
    }

    // Close input for OBC Script
    OBCInput.close();

    if (!found) {
        std::cout << "The Entrypoint \"" << searchEntrypoint << "\" was not found in the Script." << std::endl;
        return 0;
    }

    // Open the output file for the OBC Script
    std::ofstream OBCOutput(outputOBC);

    if (!OBCOutput) {
        std::cerr << "Error: Unable to create text output of OBC Script." << std::endl;
        return 1;
    }

    // Read from input and write to output
    char c;
    while (OBCInput.get(c)) {
        if (std::isprint(static_cast<unsigned char>(c))) {
            OBCOutput.put(c);
        }
    }

    // Close input & output for OBC Script
    OBCInput.close();
    OBCOutput.close();

    std::cout << "OBC Script (" << argv[1] << ") is viewable and saved output to " << outputOBC  << "" <<std::endl;

    return 0;
}
