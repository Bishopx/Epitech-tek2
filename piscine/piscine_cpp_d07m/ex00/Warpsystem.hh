#ifndef _WARPSYSTEM_H_
# define _WARPSYSTEM_H_

namespace WarpSystem {
	class 		QuantumReactor {

	bool	_stability;
	public:
		QuantumReactor();
		bool isStable();
		void setStability(bool stability);
	};

	class 		Core {
	
	QuantumReactor *_coreReactor;
	
	public:
		Core(QuantumReactor *);
		QuantumReactor *checkReactor();
		
	};
};

#endif /* ! _WARPSYSTEM_H_ */
