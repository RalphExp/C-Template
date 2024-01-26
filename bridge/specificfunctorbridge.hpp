#ifndef SPECIFIC_FUNCTOR_BRIDGE_HPP_
#define SPECIFIC_FUNCTOR_BRIDGE_HPP_

#include "functorbridge.hpp"

template<typename Functor, typename R, typename... Args>
class SpecificFunctorBridge : public FunctorBridge<R, Args...> {
private:
    Functor functor;
public:
    template<typename FunctorFwd>
    SpecificFunctorBridge(FunctorFwd&& functor) : functor(std::forward<FunctorFwd>(functor)) {}

    virtual SpecificFunctorBridge* clone() const override {
        return new SpecificFunctorBridge(functor);
    }
    
    virtual R invoke(Args... args) const override {
        return functor(std::forward<Args>(args)...);
    }
};

#endif