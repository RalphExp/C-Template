#ifndef FUNCTION_PTR_HPP_
#define FUNCTION_PTR_HPP_

#include "specificfunctorbridge.hpp"

using namespace std;

template <typename Signature>
class FunctionPtr;

template <typename R, typename... Args>
class FunctionPtr<R(Args...)> {
private:
    FunctorBridge<R, Args...>* bridge;

public:
    FunctionPtr() : bridge(nullptr) {}

    FunctionPtr(FunctionPtr const& other) : bridge(nullptr) {
        if (other.bridge) {
            bridge = other.bridge->clone();
        } 
    }

    FunctionPtr(FunctionPtr& other) : FunctionPtr(static_cast<FunctionPtr const&>(other)) {
        // do nothing
    }

    FunctionPtr(FunctionPtr&& other) : bridge(other.bridge) {
        other.bridge = nullptr;
    }

    // construction from arbitrary function objects:
    template<typename F>
    FunctionPtr(F&& f) : bridge(nullptr) {
        using Functor = std::decay_t<F>;
        using Bridge = SpecificFunctorBridge<Functor, R, Args...>;
        bridge = new Bridge(std::forward<F>(f));
    }

    // assignment operators:
    FunctionPtr& operator=(FunctionPtr const& other) {
        FunctionPtr tmp(other);
        swap(*this, tmp);
        return *this;
    }

    FunctionPtr& operator=(FunctionPtr&& other) {
        delete bridge;
        bridge = other.bridge;
        other.bridge = nullptr;
        return *this;
    }

    template<typename F> 
    FunctionPtr& operator=(F&& f) {
        FunctionPtr tmp(std::forward<F>(f));
        swap(*this, tmp);
        return *this;
    }

    // destructor:
    ~FunctionPtr() {
        delete bridge;
    }

    friend void swap(FunctionPtr& fp1, FunctionPtr& fp2) {
        std::swap(fp1.bridge, fp2.bridge);
    }

    explicit operator bool() const {
        return bridge == nullptr;
    }

    // invocation:
    R operator()(Args... args) const {
        return bridge->invoke(std::forward<Args>(args)...);
    }
};

#endif