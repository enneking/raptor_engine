#pragma once
#include "non_copyable.h" 


	template<class ...FuncArgs >
	class SlotBase : public NonCopyable {
	public:
		SlotBase() 
		{};
		virtual ~SlotBase() = default;

		virtual void Process(FuncArgs...) = 0;

		virtual void SetId(uint8_t id) = 0;
		virtual uint8_t GetId() = 0;

		virtual void SetPriority(uint8_t) = 0;
		virtual uint8_t GetPriority() = 0;
	};

	template<class TListener, class ... FuncArgs>
	class Slot : public SlotBase<FuncArgs...>{
	public:
		explicit Slot(TListener* const obj, void(TListener::* const func)(FuncArgs...));
		virtual void Process(FuncArgs...);

		virtual void SetId(uint8_t id);
		virtual uint8_t GetId();

		virtual void SetPriority(uint8_t);
		virtual uint8_t GetPriority();
	private:
		TListener* const obj_;
		void(TListener::* const func_)(FuncArgs...);
		uint8_t id_;
		uint8_t priority_;
	};




#include"Slot.inl"