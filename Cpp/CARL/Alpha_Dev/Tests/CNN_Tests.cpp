#include "CNN_Tests.h"
#include <vector>
#include <stdio.h>
#include "../Tests/TestData.h"
#include "../Data/Load_Data.h"

void testKernelParameters() {
    printf("Kernel Init:\n");
    Kernel k = Kernel();
    k.printFilter();

    k.setFilterParameters(NxTHREE, 4, TOP_EDGE_FILTER);
    k.printFilter();

    k.setFilterStyle(LEFT_EDGE_FILTER);
    k.printFilter();

    k.setFilterStyle(BOTTOM_EDGE_FILTER);
    k.printFilter();

    k.setFilterParameters(FIVExFIVE, TOP_RIGHT_CORNER_FILTER);
    k.printFilter();

    k.setFilterStyle(BOTTOM_RIGHT_CORNER_FILTER);
    k.printFilter();

    k.setFilterStyle(BOTTOM_LEFT_CORNER_FILTER);
    k.printFilter();

    k.setFilterStyle(TOP_LEFT_CORNER_FILTER);
    k.printFilter();

    k.setFilterParameters(SEVENxSEVEN, ASCENDING_FILTER);
    k.printFilter();

    k.setFilterStyle(DESCENDING_FILTER);
    k.printFilter();
    
    k.setFilterStyle(VERTICAL_ASCENDING_FILTER);
    k.printFilter();

    k.setFilterStyle(VERTICAL_DESCENDING_FILTER);
    k.printFilter();
    
    k.setFilterStyle(LtoR_GRADIENT_FILTER);
    k.printFilter();
    
    k.setFilterStyle(RtoL_GRADIENT_FILTER);
    k.printFilter();
    
    k.setFilterStyle(TtoB_GRADIENT_FILTER);
    k.printFilter();
    
    k.setFilterStyle(BtoT_GRADIENT_FILTER);
    k.printFilter();

    k.setFilterParameters(ELEVENxELEVEN, TLtoBR_GRADIENT_FILTER);
    k.printFilter();
    
    k.setFilterStyle(BLtoTR_GRADIENT_FILTER);
    k.printFilter();

    k.setFilterStyle(GAUSSIAN_FILTER);
    k.printFilter();
    
    k.setFilterStyle(BALANCED_GAUSSIAN_FILTER);
    k.printFilter();
    
    k.setFilterStyle(NEGATIVE_GAUSSIAN_FILTER);
    k.printFilter();
    
    k.setFilterStyle(MODIFIED_GAUSSIAN_FILTER);
    k.printFilter();
 
    k.setFilterStyle(CONICAL_FILTER);
    k.printFilter();
     
    k.setFilterStyle(INVERSE_CONICAL_FILTER);
    k.printFilter();
}

void testCNNinit() {
    printf("Init Cnn:\n");
    CNN* cnn = new CNN();
    printf("Current Layer count: \t\t%d\n", cnn->getLayerCount());
    printf("Current Layer kernel count: \t%d\n\n", cnn->getCurrentLayer()->n_kernels);

    cnn->addNewKernel(cnn->createNewKernel(THREExN, 1, TOP_EDGE_FILTER));
    printf("Added new filter:\n");
    cnn->getCurrentLayer()->kernels[cnn->getCurrentLayer()->n_kernels - 1]->printFilter();

    cnn->addNewKernel(cnn->createNewKernel(NxTHREE, 1, RIGHT_EDGE_FILTER));
    printf("Added new filter:\n");
    cnn->getCurrentLayer()->kernels[cnn->getCurrentLayer()->n_kernels - 1]->printFilter();
    
    cnn->addNewKernel(cnn->createNewKernel(THREExTHREE, TLtoBR_GRADIENT_FILTER));
    printf("Added new filter:\n");
    cnn->getCurrentLayer()->kernels[cnn->getCurrentLayer()->n_kernels - 1]->printFilter();
    
    cnn->addNewKernel(cnn->createNewKernel(THREExTHREE, BLtoTR_GRADIENT_FILTER));
    printf("Added new filter:\n");
    cnn->getCurrentLayer()->kernels[cnn->getCurrentLayer()->n_kernels - 1]->printFilter();
    
    printf("Current Layer kernel count: \t%d\n", cnn->getCurrentLayer()->n_kernels);
}