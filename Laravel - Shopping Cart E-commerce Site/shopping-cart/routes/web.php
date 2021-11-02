<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', 'App\Http\Controllers\ProductController@getIndex')->name('product.index');

Route::get('/cart/{id}', 'App\Http\Controllers\ProductController@getAddToCart')->name('product.addToCart');

Route::get('/reduce/{id}', 'App\Http\Controllers\ProductController@getReduceByOne')->name('product.reduceByOne');
Route::get('/remove/{id}', 'App\Http\Controllers\ProductController@getRemoveItem')->name('product.remove');

Route::get('/shopping-cart', 'App\Http\Controllers\ProductController@getCart')->name('product.shoppingCart');

Route::get('/signup', 'App\Http\Controllers\UserController@getSignup')->name('user.signup')->middleware('guest');
Route::post('/signup', 'App\Http\Controllers\UserController@postSignup')->name('user.signup')->middleware('guest');

Route::get('/signin', 'App\Http\Controllers\UserController@getSignin')->name('user.signin')->middleware('guest');
Route::post('/signin', 'App\Http\Controllers\UserController@postSignin')->name('user.signin')->middleware('guest');

Route::get('/user/profile', 'App\Http\Controllers\UserController@getProfile')->name('user.profile')->middleware('auth');

Route::get('/user/logout', 'App\Http\Controllers\UserController@getLogout')->name('user.logout')->middleware('auth');
