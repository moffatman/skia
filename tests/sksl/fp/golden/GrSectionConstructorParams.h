

/**************************************************************************************************
 *** This file was autogenerated from GrSectionConstructorParams.fp; do not modify.
 **************************************************************************************************/
#ifndef GrSectionConstructorParams_DEFINED
#define GrSectionConstructorParams_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"


#include "src/gpu/GrFragmentProcessor.h"

class GrSectionConstructorParams : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(float w,  int x, float y, std::vector<float> z ) {
        return std::unique_ptr<GrFragmentProcessor>(new GrSectionConstructorParams(w, x, y, z));
    }
    GrSectionConstructorParams(const GrSectionConstructorParams& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "SectionConstructorParams"; }
    float w;
private:
    GrSectionConstructorParams(float w,  int x, float y, std::vector<float> z )
    : INHERITED(kGrSectionConstructorParams_ClassID, kNone_OptimizationFlags)
    , w(w) {
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
#if GR_TEST_UTILS
    SkString onDumpInfo() const override;
#endif
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    using INHERITED = GrFragmentProcessor;
};
#endif
