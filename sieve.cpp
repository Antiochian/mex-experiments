#include "mex.hpp"
#include "mexAdapter.hpp"
#include "MatlabDataArray.hpp"

using namespace matlab::data;

double getprimes(int n);

class MexFunction : public matlab::mex::Function {
public:
	void operator() (matlab::mex::ArgumentList outputs, matlab::mex::ArgumentList inputs) {
		//checkArguments(outputs, inputs);
        //matlab::data::ArrayFactory factory;
        
		matlab::data::TypedArray<double> doubleArray0 = std::move(inputs[0]); //rvalue move destroys original input to save space/time
        
		for (auto& elem : doubleArray0) {
			elem = getprimes(elem);
		}
		outputs[0] = doubleArray0;
		/*
		matlab::data::TypedArray<double> doubleArray1 = std::move(inputs[1]);
		matlab::data::TypedArray<double> doubleArray2 = std::move(inputs[2]);
		int len = doubleArray1.getNumberOfElements();
		for (int i = 0; i < len; i++) {
			doubleArray2[i] = plusnum(doubleArray1[i], doubleArray2[i]);
		}
		outputs[1] = doubleArray2;*/

	}


	void checkArguments(matlab::mex::ArgumentList outputs, matlab::mex::ArgumentList inputs) {

		/* We want to use MATLABs built-in error reporting (rather than having to alt-tab to a
		console or something), so we need to interface with the matlab engine */
		std::shared_ptr<matlab::engine::MATLABEngine> matlabPtr = getEngine();

		matlab::data::ArrayFactory factory;

		//this error-checking needs to be hardcoded depending on my function (for example, here its checking for doubles)
		if (inputs[0].getType() != ArrayType::INT16 && inputs[0].getType() != ArrayType::INT8 && inputs[0].getType() != ArrayType::INT32) {
			//throwing an error is the same as passing a string (scalar) to the matlab engine
			matlabPtr->feval(u"error", 0, std::vector<Array>({ factory.createScalar("Not int!") }));
		};
	};

private:

};


double getprimes(int n) {
    std::vector<int> res;
    std::vector<bool> prime(n+1, true);
    for (int p = 2; p * p < n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) { prime[i] = false; }
        }
    }
    double count = 0;
    for (int i = 2; i < n + 1; i++) {
        if (prime[i]) { count++; }
    }
    return count;
}