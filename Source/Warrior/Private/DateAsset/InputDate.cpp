// xiaoxiao


#include "DateAsset/InputDate.h"

UInputAction* UInputDate::FindTagAction(const FGameplayTag &InputTag)const {
	for (FInputTagToAction TagToAction:InputTagToAction) {
		if (TagToAction.InputTag.MatchesTag(InputTag)) {
			return TagToAction.InputAction;
		}
	 }
	return nullptr;
}

