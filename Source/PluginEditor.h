/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class NoiseGenAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    
    enum {
        paramControlHeight = 40,
        paramLabelWidth    = 80,
        paramSliderWidth   = 300
    };
    
    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
    NoiseGenAudioProcessorEditor (NoiseGenAudioProcessor&);
    ~NoiseGenAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
        
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NoiseGenAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& valueTreeState;

    juce::Label gainLabel;
    juce::Slider gainSlider;
    std::unique_ptr<SliderAttachment> gainAttachment;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseGenAudioProcessorEditor)
};
