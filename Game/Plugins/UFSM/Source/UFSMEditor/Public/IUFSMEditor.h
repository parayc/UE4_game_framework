/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///			Copyright 2017 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ModuleManager.h"
#include "IDetailCustomization.h"
#include "IPropertyChangeListener.h"

#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FToolBarBuilder;
class FMenuBuilder;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static const FName FSMVisualizerTabName("FSMVisualizerWindow");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define LOCTEXT_NAMESPACE "Synaptech"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class IFSMEditor : public IModuleInterface {
public:
	static inline IFSMEditor &Get() {return FModuleManager::LoadModuleChecked<IFSMEditor>("UFSMEditor");}
	static inline bool IsAvailable() {return FModuleManager::Get().IsModuleLoaded("UFSMEditor");}
};

class FSMEditor : public IFSMEditor {
private:
	TSharedRef<SDockTab> OnSpawnFSMVisualizerTab(const FSpawnTabArgs& SpawnTabArgs);
	TSharedPtr<FUICommandList> FSMWindowCommands;
	//
	void AddToolbarExtension(FToolBarBuilder &Builder);
	void AddMenuExtension(FMenuBuilder &Builder);
	//
	//
	bool HandleSettingsSaved() {
		const auto &Settings = GetMutableDefault<UFSMSettings>();
		Settings->SaveConfig();
		Settings->UpdateDefaultConfigFile();
	return true;}
	//
	void RegisterSettings() {
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings")) {
			ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");
			SettingsContainer->DescribeCategory("Synaptech",LOCTEXT("SynaptechCategoryName","Synaptech"),
			LOCTEXT("SynaptechCategoryDescription","Configuration of Synaptech Systems."));
			//
			ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project","Synaptech","UFSMEditor",
				LOCTEXT("FSMEditorName","FSM Settings"),
				LOCTEXT("FSMEditorDescription","General settings for the FSM Plugin"),
			GetMutableDefault<UFSMSettings>());
			//
			if (SettingsSection.IsValid()) {SettingsSection->OnModified().BindRaw(this,&FSMEditor::HandleSettingsSaved);}
		}
	}
	//
	void UnregisterSettings() {
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings")) {
			SettingsModule->UnregisterSettings("Project","Synaptech","FSMEditor");
		}
	}
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override {return true;}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class UFSMEDITOR_API FSMCustomDetails : public IDetailCustomization {
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder &DetailBuilder) override;
	//
	static TSharedRef<IDetailCustomization> MakeInstance();
	static FReply VisualizeFSM(IDetailLayoutBuilder* DetailBuilder);
	static FReply AddFunctions(IDetailLayoutBuilder* DetailBuilder);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////