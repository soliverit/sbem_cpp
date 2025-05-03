#include "sbem_improver.h"
/*=== Constructors ===*/
SbemImprover::SbemImprover() {}
SbemImprover::SbemImprover(std::shared_ptr<SbemModel> sbemModel){}
// Constants

/*=== Getters ===*/
SbemModel SbemImprover::getModel() { return *model; }
/*=== Setters ===*/

/*=== The rest ===*/
