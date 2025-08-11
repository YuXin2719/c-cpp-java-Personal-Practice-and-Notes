package com.easyjava.entity.query;

import java.math.BigDecimal;

/**
 * @description:查询对象
 * @Author:YuXin
 * @date:2025/02/26
 */
public class PlayerQuery {
	/**
	 * 
	 */
	private Integer id;

	/**
	 * 
	 */
	private String name;

	private String nameFuzzy;

	/**
	 * 
	 */
	private String sex;

	private String sexFuzzy;

	/**
	 * 
	 */
	private String email;

	private String emailFuzzy;

	/**
	 * 
	 */
	private Integer level;

	/**
	 * 
	 */
	private Integer exp;

	/**
	 * 
	 */
	private BigDecimal gold;

	public void setId(Integer id) {
		this.id = id;
	}

	public Integer getId() {
		return this.id;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public String getSex() {
		return this.sex;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getEmail() {
		return this.email;
	}

	public void setLevel(Integer level) {
		this.level = level;
	}

	public Integer getLevel() {
		return this.level;
	}

	public void setExp(Integer exp) {
		this.exp = exp;
	}

	public Integer getExp() {
		return this.exp;
	}

	public void setGold(BigDecimal gold) {
		this.gold = gold;
	}

	public BigDecimal getGold() {
		return this.gold;
	}

	public void setNameFuzzy(String nameFuzzy) {
		this.nameFuzzy = nameFuzzy;
	}

	public String getNameFuzzy() {
		return this.nameFuzzy;
	}

	public void setSexFuzzy(String sexFuzzy) {
		this.sexFuzzy = sexFuzzy;
	}

	public String getSexFuzzy() {
		return this.sexFuzzy;
	}

	public void setEmailFuzzy(String emailFuzzy) {
		this.emailFuzzy = emailFuzzy;
	}

	public String getEmailFuzzy() {
		return this.emailFuzzy;
	}

}