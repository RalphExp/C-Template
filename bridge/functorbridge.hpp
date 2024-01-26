#ifndef FUNCTOR_BRIDGE_HPP_
#define FUNCTOR_BRIDGE_HPP_

template<typename R, typename... Args>
class FunctorBridge {
public:
    virtual ~FunctorBridge() {}
    virtual FunctorBridge* clone() const = 0;
    virtual R invoke(Args... args) const = 0;
};

#endif