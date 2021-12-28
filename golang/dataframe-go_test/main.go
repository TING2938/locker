package main

import (
	"context"
	"fmt"

	dataframe "github.com/rocketlaunchr/dataframe-go"
	"github.com/rocketlaunchr/dataframe-go/forecast/interpolation"
)

func interpolate_method(df *dataframe.SeriesFloat64) *dataframe.OrderedMapIntFloat64 {
	opts := interpolation.InterpolateOptions{
		Method:        interpolation.ForwardFill{},
		Limit:         new(int),
		FillDirection: interpolation.Forward | interpolation.Backward,
		FillRegion:    nil,
		InPlace:       false,
		DontLock:      false,
		R:             &dataframe.Range{},
		HorizAxis:     nil,
	}
	ctx := context.Background()
	// return_data map[interface{}]*dataframe.OrderedMapIntFloat64
	return_data, _ := interpolation.Interpolate(ctx, df, opts)
	return_series := return_data.(*dataframe.OrderedMapIntFloat64)
	//fmt.Print(err)

	return return_series
}

func main() {
	s1 := dataframe.NewSeriesFloat64("64", nil, 1, 2, 3, 4, 5, 6, 7, 8)
	s2 := dataframe.NewSeriesFloat64("sales", nil, 50.3, 23.4, 56.2, nil, nil, 84.2, 72, 89)
	df := dataframe.NewDataFrame(s1, s2)
	fmt.Print(df.Table())
	ret := interpolate_method(s2)
	fmt.Print(ret)
}
