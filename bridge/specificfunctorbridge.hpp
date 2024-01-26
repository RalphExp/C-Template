#ifndef SPECIFIC_FUNCTOR_BRIDGE_HPP_
#define SPECIFIC_FUNCTOR_BRIDGE_HPP_

#include "functorbridge.hpp"
#include "isequalitycomparable.hpp"

template<typename Functor, typename R, typename... Args>
class SpecificFunctorBridge : public FunctorBridge<R, Args...> {
private:
    Functor functor;
public:
    template<typename FunctorFwd>
    SpecificFunctorBridge(FunctorFwd&& f) : functor(std::forward<FunctorFwd>(f)) {}

    virtual SpecificFunctorBridge* clone() const override {
        return new SpecificFunctorBridge(functor);
    }
    
    virtual R invoke(Args&& ...args) const override {
        return functor(std::forward<Args>(args)...);
    }

    virtual bool equals(FunctorBridge<R, Args...> const* fb) const override {
        if (auto specFb = dynamic_cast<SpecificFunctorBridge const*>(fb)) {
            return TryEquals<Functor>::equals(functor, specFb->functor);
            // return functor == specFb->functor;
        }
        return false;
    }
};

#endif