// Diego Gallo All Rights Reserved


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/WarriorAttributeSet.h"

struct FWarriorDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)

	FWarriorDamageCapture()
	{
		DECLARE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet,AttackPower,Source,false)
		DECLARE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DefensePower, Target, false)
	}
};

static const FWarriorDamageCapture& GetWarriorDamageCapture()
{
	static FWarriorDamageCapture WarriorDamageCapture;
	return WarriorDamageCapture;
}

UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	/* Slow way of doing capture*/
	/*FProperty* AttackPowerProperty = FindFieldChecked<FProperty>(
		UWarriorAttributeSet::StaticClass(),
		GET_MEMBER_NAME_CHECKED(UWarriorAttributeSet, AttackPower)
	);

	FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDefinition(
		AttackPowerProperty,
		EGameplayEffectAttributeCaptureSource::Source,
		false
	);

	RelevantAttributesToCapture.Add(AttackPowerCaptureDefinition);*/

	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DefensePowerDef);
}
