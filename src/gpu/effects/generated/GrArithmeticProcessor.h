/*
 * Copyright 2020 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrArithmeticProcessor.fp; do not modify.
 **************************************************************************************************/
#ifndef GrArithmeticProcessor_DEFINED
#define GrArithmeticProcessor_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"

#include "include/effects/SkArithmeticImageFilter.h"

#include "src/gpu/GrFragmentProcessor.h"

class GrArithmeticProcessor : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> srcFP,
                                                     std::unique_ptr<GrFragmentProcessor> dstFP,
                                                     const ArithmeticFPInputs& inputs) {
        return std::unique_ptr<GrFragmentProcessor>(new GrArithmeticProcessor(
                std::move(srcFP), std::move(dstFP),
                SkV4{inputs.fK[0], inputs.fK[1], inputs.fK[2], inputs.fK[3]},
                inputs.fEnforcePMColor));
    }
    GrArithmeticProcessor(const GrArithmeticProcessor& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "ArithmeticProcessor"; }
    SkV4 k;
    bool enforcePMColor;

private:
    GrArithmeticProcessor(std::unique_ptr<GrFragmentProcessor> srcFP,
                          std::unique_ptr<GrFragmentProcessor> dstFP,
                          SkV4 k,
                          bool enforcePMColor)
            : INHERITED(kGrArithmeticProcessor_ClassID, (OptimizationFlags)kNone_OptimizationFlags)
            , k(k)
            , enforcePMColor(enforcePMColor) {
        this->registerChild(std::move(srcFP), SkSL::SampleUsage::PassThrough());
        SkASSERT(dstFP);
        this->registerChild(std::move(dstFP), SkSL::SampleUsage::PassThrough());
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
